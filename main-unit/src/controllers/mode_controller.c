#include <unistd.h>

#include "esp_log.h"

#include "controllers/mode_controller.h"
#include "utils/type_utils.h"

static system_mode_t current_mode = mode_idle;
static char* TAG = "mode_controller";

/**
 * @brief Set the value of the current mode
 *
 * @param mode Value to set the current mode to
 * @return true if mode is updated, else false
 */
bool mode_controller_set_mode(const system_mode_t mode);

void mode_controller_init(void)
{
}

system_mode_t mode_controller_get_mode(void)
{
    return current_mode;
}

bool mode_controller_update(const system_data_t* const system_data)
{
    if (system_data == NULL)
    {
        return false;
    }

    switch (current_mode)
    {
        case mode_idle:
            /* code */
            break;
        case mode_timer:
            /* code */
            break;
        case mode_dnd:
            /* code */
            break;
        case mode_config:
            /* code */
            break;
        default:
            ESP_LOGE(TAG, "Failed updating current mode: %s", system_mode_string(current_mode));
            return false;
    }
    return true;
}

bool mode_controller_set_mode(const system_mode_t mode)
{
    // sanitize inputs
    if (!is_valid_enum(mode, mode_end_of_range))
    {
        return false;
    }

    current_mode = mode;
    return true;
}
