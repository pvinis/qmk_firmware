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
