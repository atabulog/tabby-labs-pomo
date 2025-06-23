#include <unistd.h>

#include "types/hms_duration.h"
#include "utils/time_utils.h"

bool microseconds_to_hms(uint32_t microseconds, hms_duration_t* const hms_duration)
{
    // input sanitization
    if (hms_duration == NULL)
    {
        return false;
    }

    uint32_t total_microseconds = microseconds;

    hms_duration->hours = total_microseconds / MICROSECONDS_PER_HOUR;
    total_microseconds %= (uint32_t) MICROSECONDS_PER_HOUR;

    hms_duration->minutes = total_microseconds / MICROSECONDS_PER_MINUTE;
    total_microseconds %= (uint32_t) MICROSECONDS_PER_MINUTE;

    hms_duration->seconds = total_microseconds / MICROSECONDS_PER_SECOND;
    total_microseconds %= (uint32_t) MICROSECONDS_PER_SECOND;

    hms_duration->milliseconds = total_microseconds / MICROSECONDS_PER_MILLISECOND;
    hms_duration->microseconds = total_microseconds % (uint32_t) MICROSECONDS_PER_MILLISECOND;

    return true;
}