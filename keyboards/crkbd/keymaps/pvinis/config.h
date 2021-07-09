#pragma once


#define MASTER_LEFT
// #define MASTER_RIGHT

#define USE_SERIAL_PD2


#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_SPLIT
#    undef RGBLED_NUM
#    define RGBLED_NUM 27
#endif

#define OLED_FONT_H "users/pvinis/glcdfont-pvinis.h"
