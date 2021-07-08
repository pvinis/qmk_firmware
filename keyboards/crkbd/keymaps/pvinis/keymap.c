// pvinis corne
// qmk flash --keyboard crkbd --keymap pvinis
// ,------------------------------------.          ┌────┬────┬────┬────┬────┬────┬──────┐
// |      |    |    |    |    |    |    |          │    │    │    │    │    │    │      │
// |------+----+----+----+----+---------|          ├────┼────┼────┼────┼────┼────┼──────┤
// |      |    |    |    |    |    |    |          │    │    │    │    │    │    │      │
// |--- I NEED TO FIX THIS ---x----x----|    |          │    ├────╆━━━━╅────┼────┼────┼──────┤
// |      |    |    |    |    |    |----|          ├────┤    ┃    ┃    │    │    │      │
// |------+----+----+----x----x----|    |          │    ├────╄━━━━╃────┼────┼────┼──────┤
// |      |    |    |    |    |    |    |          │    │    │    │    │    │    │      │
// `------+----+----+----+----+---------'          └────┴────┼────┼────┼────┼────┼────┬─┘
//   |    |    |    |    |    |                              │    │    │    │    │    │
//   `------------------------'                              └────┴────┴────┴────┴────┘
//                              ,---------.      ┌────┬────┐
//                              |    |    |      │    │    │
//                         ,----+----+----|      ├────┼────┼────┐
//                         |    |    |    |      │    │    │    │
//                         |    |    |----|      ├────┤    │    │
//                         |    |    |    |      │    │    │    │
//                         `--------------'      └────┴────┴────┘


#include QMK_KEYBOARD_H
#include "pvinis.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LR_BASE] = LAYOUT_split_3x6_3_wrapper(
        // clang-format off
        KC_TAB , ___________________________________________,    _______, _______, _______, _______, _______, KBCTL  ,
        PV_ESCC, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_ENT ,
        KC_LSFT, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_RSFT,
                                   KC_LGUI, SYMBOL , NUMBSPC,    KC_SPC , SYSCTL , NUMBERS
        // clang-format on
        ),

    [LR_QWERTY] = LAYOUT_split_3x6_3_wrapper(
        // clang-format off
        _______, _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, _______,
        _______, _____________MOD_QWERTY_L2_________________,    _________________QWERTY_R2_________________, _______,
        _______, _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
        // clang-format on
        ),

    [LR_SYMBOL] = LAYOUT_split_3x6_3_wrapper(
        // clang-format off
        _______, _________________SYMBOL_L1_________________,    _________________SYMBOL_R1_________________, _______,
        _______, _________________SYMBOL_L2_________________,    _________________SYMBOL_R2_________________, _______,
        _______, _________________SYMBOL_L3_________________,    _________________SYMBOL_R3_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
        // clang-format on
        ),

    [LR_SYSCTL] = LAYOUT_split_3x6_3_wrapper(
        // clang-format off
        _______, _________________SYSCTL_L1_________________,    _________________SYSCTL_R1_________________, _______,
        _______, _________________SYSCTL_L2_________________,    _________________SYSCTL_R2_________________, _______,
        _______, _________________SYSCTL_L3_________________,    _________________SYSCTL_R3_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
        // clang-format on
        ),

    [LR_NUMBERS] = LAYOUT_split_3x6_3_wrapper(
        // clang-format off
        _______, ________________NUMBERS_L1_________________,    ________________NUMBERS_R1_________________, _______,
        _______, ________________NUMBERS_L2_________________,    ________________NUMBERS_R2_________________, _______,
        _______, ________________NUMBERS_L3_________________,    ________________NUMBERS_R3_________________, _______,
                                   _______, _______, _______,    KC_0   , _______, _______
        // clang-format on
        ),

    [LR_KBCTL] = LAYOUT_split_3x6_3_wrapper(
        // clang-format off
        _______, __________________KBCTL_L1_________________,    __________________KBCTL_R1_________________, _______,
        _______, __________________KBCTL_L2_________________,    __________________KBCTL_R2_________________, _______,
        _______, __________________KBCTL_L3_________________,    __________________KBCTL_R3_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
        // clang-format on
        ),

    [LR_WARZONE] = LAYOUT_split_3x6_3_wrapper(
        // WASD movement
        // E melee (maybe use mouse?)
        // R reload
        // Q flash/heartbeat
        // T, is it used? maybe replace with something else
        // F, is it used? maybe replace with something else
        // G, is it used? maybe replace with something else
        // X throw loadie
        // C, is it used? maybe replace with something else
        // V, is it used? maybe replace with something else
        // 3 UAV etc
        // 4 put armor plate
        // M map
        // Lalt ping
        // clang-format off
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,    KC_3   , KC_6   , _______, _______, BASE   , KC_ESC ,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,    KC_4   , _______, _______, _______, _______, KC_ENT ,
        KC_LSFT, KC_3   , KC_X   , KC_C   , KC_V   , KC_4   ,    KC_5   , _______, _______, _______, _______, KC_LWIN,
                                   KC_M   , KC_SPC , KC_LALT,    KC_LWIN, _______, _______
        // clang-format on
        ),
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return rotation;
}

static void render_status(void) {
    if (!userspace_config.is_oled_on) return;

    switch (get_highest_layer(layer_state)) {
        case LR_QWERTY:
            oled_write_P(PSTR("hello\n"), false);
            oled_write_P(PSTR("there!\n"), false);
            break;
        case LR_WARZONE:
            oled_write_P(PSTR("WHERE\n"), false);
            oled_write_P(PSTR("WE\n"), false);
            oled_write_P(PSTR("DROPPIN,\n"), false);
            oled_write_P(PSTR("BOYS?\n"), false);
            break;
        default:
            oled_write_P(PSTR("hmm"), false);
            oled_write_P(PSTR("layer deets\n"), false);
            oled_write_P(PSTR("missing\n"), false);
            oled_write_P(PSTR("\n"), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_status();
    }
}
#endif


void set_layer_indicator(uint8_t hue, uint8_t sat, uint8_t val) {
#ifdef RGBLIGHT_ENABLE
    rgblight_sethsv_at(hue, sat, val, 8);
#endif
}

uint32_t layer_state_set_user_keymap(uint32_t state) {
    switch (biton32(state)) {
        case LR_SYSCTL:
            set_layer_indicator(HSV_BLUE);
            break;

        case LR_KBCTL:
            set_layer_indicator(HSV_RED);
            break;

        case LR_SYMBOL:
            set_layer_indicator(HSV_GREEN);
            break;

        case LR_NUMBERS:
            set_layer_indicator(HSV_ORANGE);
            break;

        default:
            set_layer_indicator(HSV_BLACK);
            break;
    }
    return state;
}


void keyboard_post_init_user_keymap(void) { layer_on(LR_QWERTY); }
