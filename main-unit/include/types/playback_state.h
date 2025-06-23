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

/**
 * @brief Converts a playback_state_t enum value to its corresponding string representation.
 * @param state The playback_state_t value.
 * @return const char* String representation of the enum value.
 */
static inline const char* playback_state_to_string(playback_state_t state)
{
    switch (state)
    {
        case playback_idle:
            return "idle";
        case playback_running:
            return "running";
        case playback_paused:
            return "paused";
        case playback_completed:
            return "completed";
        case playback_stopped:
            return "stopped";
        case playback_error:
            return "error";
        case playback_end_of_range:
            return "end_of_range";
        default:
            return "unknown";
    }
}

#endif // PLAYBACK_STATE_H