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

#endif //SYSTEM_MODE_H