#ifndef POMO_CONTROLLER_H
#define POMO_CONTROLLER_H

#include <stdint.h>
#include <stdbool.h>

void pomo_controller_init(void);


void pomo_controller_update(void); //TODO: Include correct typed arguments

void pomo_controller_toggle_playback(void);

#endif //POMO_CONTROLLER_H