#pragma once


#ifdef PRODUCT
    #undef PRODUCT
    #define PRODUCT BDN9 rev2 Keyboard - pvinis
#endif


#ifdef ENCODER_ENABLE
    #define ENCODER_RESOLUTIONS { 4, 2, 2 }
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#endif
