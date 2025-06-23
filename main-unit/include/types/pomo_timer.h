#ifndef TIMER_STATE_H
#define TIMER_STATE_H

#include <stdint.h>

#include "playback_state.h"

/**
 * @brief Timer data type maintains pomodoro time state
 */
typedef struct
{
    uint32_t target_ms;
    uint32_t reference_ms;
    uint32_t elapsed_ms;
    playback_state_t playback;
    float progress; // 0.0 to 1.0
} pomo_timer_state_t;

#endif // TIMER_STATE_H