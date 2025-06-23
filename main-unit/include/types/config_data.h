#ifndef CONFIG_DATA_H
#define CONFIG_DATA_H

#include <stdint.h>

#include "types/rgb.h"

typedef struct 
{
    uint8_t max_led_brightness; //maximum timer led brightness 0-100
    uint8_t max_screen_brightness; //maximum timer led brightness 0-100
    rgb_t color_gradient[5]; //color gradient used in timer status
    rgb_t dnd_color; //color of do not disturb mode
    rgb_t request_color; //color of active request status led
}config_data_t;


#endif //CONFIG_DATA_H