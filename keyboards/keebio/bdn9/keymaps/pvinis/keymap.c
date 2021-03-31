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
    // │  1 │    │  2 │
    // ├────┼────┼────┤
    // │PREV│PLAY│NEXT│
    // └────┴────┴────┘
    [LR_BASE] = LAYOUT(
        _______      , KC_MUTE, _______,
        MO(LR_SYMBOL), _______, MO(LR_SYSCTL),
        KC_MPRV      , KC_MPLY, KC_MNXT
    ),

    // ┌────┬────┬────┐
    // │    │    │    │
    // ├────┼────┼────┤
    // │  1 │    │  2 │
    // ├────┼────┼────┤
    // │    │    │    │
    // └────┴────┴────┘
    [LR_SYMBOL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, _______,
        XXXXXXX, XXXXXXX , XXXXXXX
    ),

    // ┌────┬────┬────┐
    // │    │    │    │
    // ├────┼────┼────┤
    // │  1 │    │  2 │
    // ├────┼────┼────┤
    // │    │    │roro│
    // └────┴────┴────┘
    [LR_SYSCTL] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_STOP,
        _______, XXXXXXX, _______,
        XXXXXXX, XXXXXXX , HYPR(KC_8)
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
            if (layer_state_is(LR_SYMBOL)) {
                // rgblight_increase_hue();
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (layer_state_is(LR_SYMBOL)) {
                // rgblight_decrease_hue();
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else if (index == ROT_RIGHT) {
        if (clockwise) {
            tap_code(KC_COMMA);
        } else {
            tap_code(KC_DOT);
        }
    }
}
#endif

// lights

// lights For layers


// keyboard initialization
void keyboard_post_init_user_keymap(void) {
#ifdef RGBLIGHT_ENABLE
    // rgblight_enable();             // Enable RGB by default
    // rgblight_sethsv(180, 255, 255);  // Set default HSV - red hue, full saturation, full brightness
#endif

#ifdef RGB_MATRIX_ENABLE
    // rgb_matrix_enable();  // Enable RGB by default
    rgb_matrix_set_color_all(35, 186, 60);
#endif
}

/**
 * Layer Switch
 */
layer_state_t layer_state_set_keymap (layer_state_t state) {
    switch (get_highest_layer(state)) {
        case LR_BASE:
        #if defined(RGBLIGHT_ENABLE)
            // rgb_layer_helper(HSV_TEAL);
        #endif
            break;
        case LR_SYMBOL:
        #if defined(RGBLIGHT_ENABLE)
            // rgb_layer_helper(HSV_CYAN);
        #endif
            break;
        case LR_SYSCTL:
        #if defined(RGBLIGHT_ENABLE)
            // rgb_layer_helper(HSV_AZURE);
        #endif
            break;
        case LR_KBCTL:
        #if defined(RGBLIGHT_ENABLE)
            // rgb_layer_helper(HSV_PINK);
        #endif
            break;
        default:
            break;
    }
    return state;
}



void eeconfig_init_user (void) {
//   rgblight_sethsv_orange();  // Set it to orange by default
    rgb_matrix_set_color_all(35, 186, 60);
}

