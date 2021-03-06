#pragma once

#include "quantum.h"


// My own keycodes.
enum userspace_custom_keycodes {
    PV_ = SAFE_RANGE,


    PV_VRSN,  // Print firmware version.
    PV_CMPL,  // Print the compile command of the keyboard.
    PV_MAKE,  // Print the compile and flash command of the keyboard.
    PV_RST,   // Reset keyboard.

    PV_SSNC,  // Play Sonic Ring.
    PV_SCIN,  // Play Coin Sound.

    PV_HMDP,  // Dump heatmap data.

    PV_TEST,  // For quick testing purposes.

    PV_L_KNTTGL,  // Toggle knight light.
    PV_OLED_TGL,  // Toggle the OLED.


    PV_SAFE_RANGE,  // Used for extra keycodes in individual keymaps.
};

enum tap_dance_indexes {
    // tap dance
    TD_FLSH,  // flash keyboard (as if the physical flash key was pressed)
};

#define ALLM(kc)     LCAG(kc)            // Easier name for left ctrl-alt-gui.
#define PV_ESCC      CTL_T(KC_ESC)       // esc on tap, ctrl on hold.
#define PV_LOCK      LCTL(LSFT(KC_PWR))  // Lock computer.
#define TD_3FLS      TD(TD_FLSH)         // Tap dance 3 times for flash.
#define PV_CTLALTDEL LCTL(LALT(KC_DEL))
#define PV_SPLY      HYPR(KC_1)
#define PV_SNXT      HYPR(KC_2)
#define PV_SPRV      HYPR(KC_3)
#define PV_SMUT      HYPR(KC_4)
#define PV_SVUP      HYPR(KC_5)
#define PV_SVDN      HYPR(KC_6)


// Layers.
enum {
    LR_BASE = 0,  // used for basic keys like the surrounding ctrl, cmd, etc

    LR_QWERTY,

    LR_SYMBOL,   // symbol input (!, @, #, etc)
    LR_SYSCTL,   // system control (music, volume, keyboard flash, etc)
    LR_NUMBERS,  // numbers and numpad layer
    LR_KBCTL,    // keyboard control (version, make, flash, etc)
    LR_LRCTL,    // layer control

    LR_WARZONE,  // game layout for warzone
    LR_GAME2,    // game layout (space on the left thumb, no modifiers, etc, arrows)

    // to try
    LR_CARPALX,
    LR_COLEMAKDH,

    LR_SAFE_RANGE,  // Used for extra layers in individual keymaps.
};


// Layer switchers.
#define BASE    TO(LR_BASE)
#define QWERTY  TO(LR_QWERTY)
#define CARPALX TO(LR_CARPALX)
#define COLEMAKDH TO(LR_COLEMAKDH)
#define GAME2   TO(LR_GAME2)
#define WARZONE TO(LR_WARZONE)

#define SYMBOL  MO(LR_SYMBOL)
#define SYSCTL  MO(LR_SYSCTL)
#define NUMBERS MO(LR_NUMBERS)
#define LRCTL   MO(LR_LRCTL)

#define NUMBSPC LT(LR_NUMBERS, KC_BSPC)


// Layout parts for easy reuse between keyboard keymaps.

// Transparent.
// ┌─────┬─────┬─────┬─────┬─────┐
// │     │     │     │     │     │
// └─────┴─────┴─────┴─────┴─────┘
#define ___________________________________________ _______, _______, _______, _______, _______

// Numbers.
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │  1  │  2  │  3  │  4  │  5  │   │  6  │  7  │  8  │  9  │  0  │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define ________________NUMBERS_L__________________ KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_R__________________ KC_6, KC_7, KC_8, KC_9, KC_0

// F keys.
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │ F1  │ F2  │ F3  │ F4  │ F5  │   │ F6  │ F7  │ F8  │ F9  │ F10 │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define ______________________F_1_5________________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define ______________________F_6_10_______________ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

// QWERTY.
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │
// ├─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┤
// │  A  │  S  │  D  ┃  F  ┃  G  │   │  H  ┃  J  ┃  K  │  L  │  ;  │
// ├─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┤
// │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define _________________QWERTY_L1_________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define _________________QWERTY_L2_________________ KC_A, KC_S, KC_D, KC_F, KC_G
#define _________________QWERTY_L3_________________ KC_Z, KC_X, KC_C, KC_V, KC_B

#define _________________QWERTY_R1_________________ KC_Y, KC_U, KC_I, KC_O, KC_P
#define _________________QWERTY_R2_________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define _________________QWERTY_R3_________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

// QWERTY with mods.
// ┌───────┬───────┬───────┲━━━━━━━┱───────┐   ┌───────┲━━━━━━━┱───────┬───────┬───────┐
// │ ctl/A │ sft/S │ cmd/D ┃ opt/F ┃   G   │   │   H   ┃ opt/J ┃ cmd/K │ sft/L │ ctl/; │
// └───────┴───────┴───────┺━━━━━━━┹───────┘   └───────┺━━━━━━━┹───────┴───────┴───────┘
// #define _____________MOD_QWERTY_L2_________________  CTL_T(KC_A), SFT_T(KC_S), GUI_T(KC_D), ALT_T(KC_F),       KC_G
#define _____________MOD_QWERTY_L2_________________ KC_A, KC_S, KC_D, ALT_T(KC_F), LCA_T(KC_G)
#define _____________MOD_QWERTY_R2_________________ KC_H, ALT_T(KC_J), GUI_T(KC_K), SFT_T(KC_L), CTL_T(KC_SCLN)

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  G  |  M  |  L  |  W  |   |  Y  |  F  |  U  |  B  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  D  |  S  |  T  |  N  |  R  |   |  I  |  A  |  E  |  O  |  H  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  V  |  J  |   |  K  |  P  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________CARPALX_L1_________________ KC_Q, KC_G, KC_M, KC_L, KC_W
#define ________________CARPALX_L2_________________ KC_D, KC_S, KC_T, KC_N, KC_R
#define ________________CARPALX_L3_________________ KC_Z, KC_X, KC_C, KC_V, KC_J

#define ________________CARPALX_R1_________________ KC_Y, KC_F, KC_U, KC_B, KC_SCLN
#define ________________CARPALX_R2_________________ KC_I, KC_A, KC_E, KC_O, KC_H
#define ________________CARPALX_R3_________________ KC_K, KC_P, KC_COMM, KC_DOT, KC_SLSH

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  F  |  P  |  B  |   |  J  |  L  |  U  |  Y  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  D  |  R  |  S  |  T  |  G  |   |  M  |  N  |  E  |  I  |  O  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  D  |  V  |   |  K  |  H  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ______________COLEMAKDH_L1_________________ KC_Q, KC_W, KC_F, KC_P, KC_B
#define ______________COLEMAKDH_L2_________________ KC_A, KC_R, KC_S, KC_T, KC_G
#define ______________COLEMAKDH_L3_________________ KC_Z, KC_X, KC_C, KC_D, KC_V

#define ______________COLEMAKDH_R1_________________ KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define ______________COLEMAKDH_R2_________________ KC_M, KC_N, KC_E, KC_I, KC_O
#define ______________COLEMAKDH_R3_________________ KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH

#define __________MOD_COLEMAKDH_L2_________________ KC_A, KC_R, KC_S, ALT_T(KC_T), LCA_T(KC_G)

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  !  | @   |  {  |  }  |  _  |   |  \  |     |  `  |     |     |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  #  |  $  |  (  |  )  |  -  |   |  =  |  &  |  '  |  "  |  |  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  %  |  ^  |  [  |  ]  |  +  |   |  *  |  ~  |  <  |  >  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________SYMBOL_L1_________________ KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_UNDS
#define _________________SYMBOL_L2_________________ KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_MINS
#define _________________SYMBOL_L3_________________ KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_PLUS

#define _________________SYMBOL_R1_________________ KC_BSLS, XXXXXXX, KC_GRV, XXXXXXX, XXXXXXX
#define _________________SYMBOL_R2_________________ KC_EQL, KC_AMPR, KC_QUOT, KC_DQUO, KC_PIPE
#define _________________SYMBOL_R3_________________ KC_ASTR, KC_TILD, KC_LABK, KC_RABK, KC_SLSH


// System Control.
//                                    vol ↓                   ctl ↓
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │ F1  │ F2  │ F3  │ F4  │ F5  │   │MUTE │HOME │ ↑  │ END │LOCK │
// ├─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┤
// │ F6  │ F7  │ F8  ┃ F9  ┃ F10 │   │VOLUP┃  ← ┃ ↓  │ →  │SLEEP│ ← arrows
// ├─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┤
// │ F11 │ F12 │     │     │     │   │VOLDN│MPREV│MPLAY│MNEXT│ PWR │ ← music
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define _________________SYSCTL_L1_________________ ______________________F_1_5________________
#define _________________SYSCTL_L2_________________ ______________________F_6_10_______________
#define _________________SYSCTL_L3_________________ KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX

// clang-format off
//                                                   vol ↓                                               ctl ↓
#define _________________SYSCTL_R1_________________ KC_MUTE, KC_HOME, KC_UP  , KC_END                 , PV_LOCK
#define _________________SYSCTL_R2_________________ KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT /* < arrows */ , KC_SLEP
#define _________________SYSCTL_R3_________________ KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT /* < music */  , KC_PWR
// clang-format on

// clang-format off
#define ________________NUMBERS_L1_________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define ________________NUMBERS_L2_________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ________________NUMBERS_L3_________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
// clang-format on

// clang-format off
#define ________________NUMBERS_R1_________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0
#define ________________NUMBERS_R2_________________ XXXXXXX, KC_4   , KC_5   , KC_6   , XXXXXXX
#define ________________NUMBERS_R3_________________ KC_0   , KC_1   , KC_2   , KC_3   , XXXXXXX
// clang-format on


// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |GAME |CRPLX|XXXXX|XXXXX|XXXXX|   |XXXXX|XXXXX|CMPL |XXXXX|XXXXX|
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |XXXXX|XXXXX|XXXXX|XXXXX|XXXXX|   |XXXXX|VERSN|MAKE |RESET|XXXXX|
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |XXXXX|XXXXX|XXXXX|OLETG|RGBTG|   |XXXXX|XXXXX|XXXXX|XXXXX|XXXXX|
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// clang-format off
#define __________________KBCTL_L1_________________ PV_SSNC, PV_SCIN, PV_TEST, XXXXXXX        , XXXXXXX
#define __________________KBCTL_L2_________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX        , XXXXXXX
#define __________________KBCTL_L3_________________ XXXXXXX, PV_L_KNTTGL, XXXXXXX, PV_OLED_TGL, RGB_TOG

#define __________________KBCTL_R1_________________ XXXXXXX   , XXXXXXX, PV_CMPL, PV_HMDP, XXXXXXX
#define __________________KBCTL_R2_________________ XXXXXXX   , PV_VRSN, PV_MAKE, PV_RST , XXXXXXX
#define __________________KBCTL_R3_________________ HYPR(KC_8), XXXXXXX, XXXXXXX, XXXXXXX, PV_CTLALTDEL

// clang-format off
#define __________________LRCTL_R2_________________ XXXXXXX, COLEMAKDH, CARPALX, XXXXXXX, XXXXXXX
#define __________________LRCTL_R3_________________ XXXXXXX, QWERTY   , WARZONE, GAME2  , XXXXXXX
// clang-format on

// We need wrappers in order for these definitions, because they need to be expanded before being used as arguments to the LAYOUT_xxx macro.
#define LAYOUT_ergodox_pretty_wrapper(...) LAYOUT_ergodox_pretty(__VA_ARGS__)
#define LAYOUT_wrapper(...)                LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...)    LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)    LAYOUT_split_3x6_3(__VA_ARGS__)


// Extra stuff that might be needed.
void     keyboard_post_init_user_keymap(void);
uint32_t layer_state_set_user_keymap(uint32_t state);


typedef union {
    uint32_t raw;
    struct {
        bool is_oled_on : 1;
    };
} userspace_config_t;

extern userspace_config_t userspace_config;
