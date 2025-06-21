#include "utils/type_utils.h"

bool is_valid_enum(uint32_t value, uint32_t enum_max)
{
    return value < enum_max;
}