#ifndef TYPE_UTILS_H
#define TYPE_UTILS_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief 
 * 
 * @param value value to inspect
 * @param enum_max maximum enumeration value 
 * @return true if value in valid enum range, else false
 * @note Enums must be base zero and increase monotonically
 */
bool is_valid_enum(uint32_t value, uint32_t enum_max);

#endif //TYPE_UTILS_H