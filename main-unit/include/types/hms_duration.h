#ifndef HMS_DURATION_H
#define HMS_DURATION_H

#include <stdint.h>

typedef struct
{
    uint8_t hours;         // integer number of hours
    uint8_t minutes;       // integer number of minutes
    uint8_t seconds;       // integer number of seconds
    uint32_t milliseconds; // integer number of milliseconds
    uint32_t microseconds; // integer number of microseconds
} hms_duration_t;

#endif // HMS_DURATION_H