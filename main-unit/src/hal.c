#include "driver/gpio.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"     // Core definitions (must be included first)
#include "freertos/task.h"         // Task creation, delays, priorities
#include "freertos/queue.h"        // Queues

#include "hal.h"


typedef enum 
{
    button_primary = 0,
    button_secondary
} button_event_t;

static QueueHandle_t button_event_queue;

static void IRAM_ATTR hal_btn_isr_handler(void *arg)
{
    //interpret argument
    uint32_t gpio_pin = (uint32_t)arg;
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
            ESP_LOGE("hal_btn_isr_handler", "Unknown GPIO pin: %d", (int)gpio_pin);
            return; // unknown pin
    }

    // Handle button press
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xQueueSendFromISR(button_event_queue, &event, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken) 
    {
        portYIELD_FROM_ISR();
    }
}


void hal_btn_task(void *arg)
{
    button_event_t event;
    while (1) 
    {
        if (!xQueueReceive(button_event_queue, &event, portMAX_DELAY)) 
        {
            continue; // ignore error
        }
        
        switch (event)
        {
        case button_primary:
            //todo: Handle media controller call here
            break;
        
        case button_secondary:
            //todo: Handle media controller call here
            break;
        default:
            break;
        }
    }
}

void hal_init(void)
{
    gpio_config_t io_conf = 
    {
        .pin_bit_mask = (1ULL << BTN_PRIMARY_GPIO) | (1ULL << BTN_SECONDARY_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,  // external pull-up in your design
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_NEGEDGE       // falling edge interrupt
    };
    gpio_config(&io_conf);

    button_event_queue = xQueueCreate(10, sizeof(button_event_t));
    if (button_event_queue == NULL) 
    {
        ESP_LOGE("hal_btn_task", "Failed to create button event queue");
        return;
    }

    gpio_install_isr_service(0); // default config
    gpio_isr_handler_add(BTN_PRIMARY_GPIO, hal_btn_isr_handler, NULL);
    gpio_isr_handler_add(BTN_SECONDARY_GPIO, hal_btn_isr_handler, NULL);

    //link ISR events to task
    xTaskCreate(hal_btn_task, "hal_btn_task", 2048, NULL, 10, NULL);
}