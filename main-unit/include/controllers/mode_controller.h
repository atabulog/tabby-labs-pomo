#ifndef MODE_CONTROLLER_H
#define MODE_CONTROLLER_H

#include <stdbool.h>

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


bool mode_controller_update(void (*callback)(const system_mode_t mode));



#endif //MODE_CONTROLLER_H