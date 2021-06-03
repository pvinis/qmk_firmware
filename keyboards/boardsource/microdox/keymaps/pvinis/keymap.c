// pvinis microdox
// qmk flash --keyboard boardsource/microdox --keymap pvinis
// ,-----------------------------.         ┌────┬────┬────┬────┬────┐
// |    |    |    |    |    |    |         │    │    │    │    │    │
// |----+----+----+----x----x----|         ├────╆━━━━╅────┼────┼────┤
// |    |    |    |    |    |    |         │    ┃    ┃    │    │    │
// |----+----+----+----x----x----+----.    ├────╄━━━━╃────┼────┼────┤
// |    |    |    |    |    |    |    |    │    │    │    │    │    │
// `-------------------+----+----+----/    └┬───┴┬───┴┬───┴┬───┴────┘
//                    |    |    |    |      │    │    │    │
//                    `----+---------'      └────┴────┴────┘


#include QMK_KEYBOARD_H
#include "pvinis.h"
#include "split_util.h"









enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define KC_CTSC RCTL_T(KC_SCLN)
#define LOWER_SPC LT(_LOWER, KC_SPC)
#define RASE_BACK LT(_RAISE, KC_BSPC)
#define SHFT_Z MT(MOD_LSFT, KC_Z)
#define SHIFT_SLASH MT(MOD_RSFT,KC_SLSH)
#define RASE_ENT LT(_RAISE, KC_ENT)
#define CTRL_A MT(MOD_LCTL,KC_A)
#define PREVWINDOW MT(MOD_LCTL, KC_LEFT)
#define NEXTWINDOW MT(MOD_LCTL, KC_RGHT)
#define SCTLSPC LT(LR_SYSCTL, KC_SPC)
#define SBLBSPC LT(LR_SYMBOL, KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LR_BASE] = LAYOUT_split_3x5_3_wrapper(
        _______, _______, _______, _______, PV_RST ,      PV_RST , PV_MAKE, _______, _______, BASE   ,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, WARZONE,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                         KC_LGUI , SYMBOL , SBLBSPC,      SCTLSPC, SYSCTL , SYSCTL2
    ),

  [LR_QWERTY] = LAYOUT_split_3x5_3_wrapper(
        _________________QWERTY_L1_________________,      _________________QWERTY_R1_________________,
        _____________MOD_QWERTY_L2_________________,      _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________,      _________________QWERTY_R3_________________,
                          _______, _______, _______,      _______, _______, _______
  ),

//   [_QWERTY] = LAYOUT_split_3x5_3(
//         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
//       CTRL_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_CTSC,
//      SHFT_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M, KC_COMM,  KC_DOT, SHIFT_SLASH,
//                        MO(_LOWER),MO(_RAISE), RASE_ENT,       MO(_LOWER),MO(_RAISE), KC_TAB
//     ),
//   [_RAISE] = LAYOUT_split_3x5_3(
//         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
//       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT,
//      KC_LSFT, KC_GRV, PREVWINDOW, NEXTWINDOW, XXXXXXX,          KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
//                          _______, KC_LGUI, KC_ENT,           _______,  _______, _______
//                          ),
//   [_LOWER] = LAYOUT_split_3x5_3(
//        KC_ESC,   XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_DQT,
//        KC_ESC,   XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_DQT,
//        KC_ESC,   KC_TILD, PREVWINDOW, NEXTWINDOW, RGB_MODE_FORWARD,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
//                             _______,  _______,  KC_ENT,         _______,  _______, _______
//                             ),

    [LR_SYMBOL] = LAYOUT_split_3x5_3_wrapper(
        _________________SYMBOL_L1_________________,      _________________SYMBOL_R1_________________,
        _________________SYMBOL_L2_________________,      _________________SYMBOL_R2_________________,
        _________________SYMBOL_L3_________________,      _________________SYMBOL_R3_________________,
                          _______, _______, _______,      _______, _______, _______
    ),

    [LR_SYSCTL] = LAYOUT_split_3x5_3_wrapper(
        _________________SYSCTL_L1_________________,      _________________SYSCTL_R1_________________,
        _________________SYSCTL_L2_________________,      _________________SYSCTL_R2_________________,
        _________________SYSCTL_L3_________________,      _________________SYSCTL_R3_________________,
                          _______, _______, _______,      _______, _______, _______
    ),

    [LR_SYSCTL2] = LAYOUT_split_3x5_3_wrapper(
        ___________________________________________,      ___________________________________________,
        ___________________________________________,      ___________________________________________,
        ___________________________________________,      ________________SYSCTL2_R3_________________,
                          _______, _______, _______,      _______, _______, _______
    ),

    [LR_WARZONE] = LAYOUT_split_3x5_3_wrapper(
        // could change E and 3 to something else
        KC_TAB , KC_Q, KC_W, KC_E, KC_R,      KC_3, KC_6   , _______, BASE   , KC_ENT,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F,      KC_4, _______, _______, _______, KC_ENT,
        KC_LSFT, KC_3, KC_X, KC_C, KC_4,      KC_5, _______, _______, _______, KC_LWIN,
                  KC_M, KC_LALT, KC_SPC,      _______, _______, _______
    ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

// static void render_logo(void) {
//   static const char PROGMEM qmk_logo[] = {
//      0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
//     0
//   };
//   oled_write_P(qmk_logo, false);
// }

static void render_status(void) {
   switch (get_highest_layer(layer_state)) {
    // case _QWERTY:
    //   oled_write_P(PSTR("Current time:\n"), false);
    //   oled_write_P(PSTR("\n"), false);
    //   oled_write_P(PSTR("FIVE o'clock\n"), false);
    //   oled_write_P(PSTR("\n"), false);
    //   break;
    // case _RAISE:
    //   oled_write_P(PSTR("B R L A O\n"), false);
    //   oled_write_P(PSTR("  ^\n"), false);
    //   oled_write_P(PSTR("Layer: Raise\n"), false);
    //   oled_write_P(PSTR("Current time:\n"), false);
    //   oled_write_P(PSTR("\n"), false);
    //   oled_write_P(PSTR("SEX  o'clock\n"), false);
    //   oled_write_P(PSTR("~~ LET'S GO ~~"), false);
    //   break;
    // case LR_SYMBOL:
    //   oled_write_P(PSTR("Current time:\n"), false);
    //   oled_write_P(PSTR("\n"), false);
    //   oled_write_P(PSTR("SEX  o'clock\n"), false);
    //   oled_write_P(PSTR("\n"), false);
    //   break;
    // case LR_SYSCTL:
    //   oled_write_P(PSTR("B R L A O\n"), false);
    //   oled_write_P(PSTR("      ^\n"), false);
    //   oled_write_P(PSTR("Layer: Adjust\n"), false);
    //   break;
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
    // render_logo();
    // oled_scroll_left();
  }
}

#endif
