#include "driver/gpio.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h" // Core definitions (must be included first)
#include "freertos/queue.h"    // Queues
#include "freertos/task.h"     // Task creation, delays, priorities

#include "hal/button_event.h"
#include "hal/discretes.h"

static QueueHandle_t button_event_queue;
static char *TAG = "hal_discretes";

static void IRAM_ATTR hal_btn_isr_handler(void *arg)
{
    // interpret argument
    uint32_t gpio_pin = (uint32_t) arg;
    button_event_t event;
    switch (gpio_pin)
    {
        case BTN_PRIMARY_GPIO:
            event = button_primary;
            break;
        case BTN_SECONDARY_GPIO:
            event = button_secondary;
            break;
        default:
            ESP_LOGE("hal_btn_isr_handler", "Unknown GPIO pin: %d", (int) gpio_pin);
            return; // unknown pin
    }

    // enqueue event data associated with button press and yield to higher priority interrupts
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xQueueSendFromISR(button_event_queue, &event, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken)
    {
        portYIELD_FROM_ISR();
    }
}

void hal_init_discretes(void)
{
    // configure buttons
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << BTN_PRIMARY_GPIO) | (1ULL << BTN_SECONDARY_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE, // external pull-up
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_NEGEDGE // falling edge interrupt
    };
    gpio_config(&io_conf);

    // create task queue for converting ISRs to tasks
    button_event_queue = xQueueCreate(10, sizeof(button_event_t));
    if (button_event_queue == NULL)
    {
        ESP_LOGE(TAG, "Failed to create button event queue");
        return;
    }

    // create GPIO ISRs for buttons
    gpio_install_isr_service(0); // default config
    gpio_isr_handler_add(BTN_PRIMARY_GPIO, hal_btn_isr_handler, NULL);
    gpio_isr_handler_add(BTN_SECONDARY_GPIO, hal_btn_isr_handler, NULL);
}