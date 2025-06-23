#ifndef SYSTEM_MODE_H
#define SYSTEM_MODE_H

/**
 * @brief Enumeration for general system mode
 */
typedef enum
{
    mode_idle=0,
    mode_timer,
    mode_dnd,
    mode_config,
    mode_end_of_range
}system_mode_t;

const char* system_mode_string(system_mode_t mode)
{ 
    switch (mode)
    {
    case mode_idle:
        return "mode_idle";
    case mode_timer:
        return "mode_timer";
    case mode_dnd:
        return "mode_dnd";
    case mode_config:
        return "mode_config";
    case mode_end_of_range:
        return "mode_end_of_range";
    default:
        return "Invalid Mode";
    }
}

#endif //SYSTEM_MODE_H