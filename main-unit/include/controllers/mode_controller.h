#ifndef MODE_CONTROLLER_H
#define MODE_CONTROLLER_H

#include <stdbool.h>

#include "types/system_data.h"
#include "types/system_mode.h"

/**
 * @brief Initialize the mode controller
 *
 */
void mode_controller_init(void);

/**
 * @brief Get a copy of the current mode
 * @return current system mode
 */
system_mode_t mode_controller_get_mode(void);

/**
 * @brief Update the current mode based on the system data
 * @return true if updated, else false
 */
bool mode_controller_update(const system_data_t* const system_data);

#endif // MODE_CONTROLLER_H