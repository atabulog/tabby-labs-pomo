#include "hal/hal.h"
#include "hal/discretes.h"

void hal_init(void)
{
    // Initialize discrete components (buttons, etc.)
    hal_init_discretes();

    // Additional HAL initializations can be added here in the future
}