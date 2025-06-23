#ifndef RGB_H
#define RGB_H

#include <stdint.h>

/**
 * @brief Generic data structure containing RGB data in 0-255
 * 
 */
typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}rgb_t;

#endif //RGB_H