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
        KC_TAB , ___________________________________________,    _______, _______, _______, _______, _______, LRCTL  ,
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

    [LR_LRCTL] = LAYOUT_split_3x6_3_wrapper(
        // clang-format off
        _______, ___________________________________________,    ___________________________________________, _______,
        _______, ___________________________________________,    ___________________________________________, _______,
        _______, ___________________________________________,    __________________LRCTL_R3_________________, _______,
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
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}

static void render_status(void) {
    oled_clear();
    oled_write_P(PSTR("Layer\n"), false);
    switch (get_highest_layer(layer_state)) {
        case LR_QWERTY:
            oled_write_P(PSTR("QWERT\n"), false);
            break;
        case LR_SYMBOL:
            oled_write_P(PSTR("SYMBL\n"), false);
            break;
        case LR_NUMBERS:
            oled_write_P(PSTR("NUMBR\n"), false);
            break;
        case LR_SYSCTL:
            oled_write_P(PSTR("SYSCT\n"), false);
            break;
        case LR_KBCTL:
            oled_write_P(PSTR("KBCTL\n"), false);
            break;
        case LR_LRCTL:
            oled_write_P(PSTR("LRCTL\n"), false);
            break;
        case LR_WARZONE:
            oled_write_P(PSTR("WAR\n"), false);
            oled_write_P(PSTR("ZONE\n\n"), false);
            oled_write_P(PSTR("LETS\n"), false);
            oled_write_P(PSTR("GO!\n"), false);
            break;
        default:
            oled_write_P(PSTR("? ? ?\n"), false);
    }
}


void render_logo(void) {
    static const char PROGMEM logo[] = {
        // clang-format off
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
        // clang-format on
    };
    oled_write_ln_P(logo, false);
}

void oled_task_user(void) {
    if (!userspace_config.is_oled_on) return;

    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
        oled_scroll_set_speed(5);
        oled_scroll_left();
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
