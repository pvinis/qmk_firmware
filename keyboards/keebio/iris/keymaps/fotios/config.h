#pragma once


#define MASTER_RIGHT

#ifdef ENCODER_ENABLE
// I connected the encoder to F4 and F5.
#    define ENCODERS_PAD_A \
        { F5 }
#    define ENCODERS_PAD_B \
        { F4 }
#    define ENCODER_RESOLUTION 2
#endif
