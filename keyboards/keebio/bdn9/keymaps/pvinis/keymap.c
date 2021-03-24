#include QMK_KEYBOARD_H
#include "pvinis.h"


// pvinis bdn9 rev2
// qmk flash --keyboard keebio/bdn9/rev2 --keymap pvinis
// ┌────┬────┬────┐
// │    │    │    │
// ├────┼────┼────┤
// │    │    │    │
// ├────┼────┼────┤
// │    │    │    │
// └────┴────┴────┘


enum encoder_names {
  ROT_LEFT,
  ROT_RIGHT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ┌────┬────┬────┐
    // │    │MUTE│    │
    // ├────┼────┼────┤
    // │  1 │roro│  2 │
    // ├────┼────┼────┤
    // │PREV│PLAY│NEXT│
    // └────┴────┴────┘
    [LR_BASE] = LAYOUT(
        _______      , KC_MUTE   , _______,
        MO(LR_SYMBOL), HYPR(KC_8), MO(LR_SYSCTL),
        KC_MPRV      , KC_MPLY   , KC_MNXT
    ),

    // └────┴────┴────┘
    [LR_SYSCTL] = LAYOUT(
    ),
    // ┌────┬────┬────┐
    // │    │    │    │
    // ├────┼────┼────┤
    // │    │    │    │
    // ├────┼────┼────┤
    // │VRSN│MAKE│RST │
    // └────┴────┴────┘
    [LR_KBCTL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, _______,
        PV_VRSN, PV_MAKE, PV_RST
    ),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == ROT_LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == ROT_RIGHT) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RGHT);
        }
    }
}
#endif
