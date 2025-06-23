#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <stdbool.h>

#include "types/hms_duration.h"

#define MICROSECONDS_PER_MILLISECOND 1000.0
#define MICROSECONDS_PER_SECOND 1000000.0
#define MICROSECONDS_PER_MINUTE 60000000.0
#define MICROSECONDS_PER_HOUR 3600000000.0
#define MILLISECONDS_PER_SECOND 1000.0
#define SECONDS_PER_MINUTE 60.0
#define MINUTES_PER_HOUR 60.0
#define HOURS_PER_DAY 24.0

/**
 * @brief Converts a time duration in microseconds to a hours minutes seconds.
 *
 * @param microseconds time duration in microseconds to convert to HMS
 * @param hms_duration pointer to the hms_duration_t structure to store the converted time
 * @return true if conversion was successful, else false
 */
bool microseconds_to_hms(uint32_t microseconds, hms_duration_t* const hms_duration);

#endif // TIME_UTILS_H