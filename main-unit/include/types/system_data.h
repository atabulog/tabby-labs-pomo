#ifndef SYSTEM_DATA_H
#define SYSTEM_DATA_H

#include <stdbool.h>
#include <stdint.h>

#include "types/config_data.h"
#include "types/playback_state.h"
#include "types/pomo_timer.h"
#include "types/system_mode.h"

typedef struct
{
    system_mode_t mode;        // Current system mode
    pomo_timer_state_t timer;  // Pomodoro timer state
    playback_state_t playback; // Playback state
    config_data_t config;      // configuration data saved to memory
} system_data_t;

#endif // SYSTEM_DATA_H
