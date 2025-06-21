#ifndef PLAYBACK_STATE_H
#define PLAYBACK_STATE_H

/**
 * @brief Enumeration for different states of timer playback.
 */
typedef enum
{
    playback_idle = 0,
    playback_running,
    playback_paused,
    playback_completed,
    playback_stopped,
    playback_error,
    playback_end_of_range
} playback_state_t;

#endif // PLAYBACK_STATE_H