// pvinis iris
// ,-----------------------------.              ,-----------------------------.
// |    |    |    |    |    |    |              |    |    |    |    |    |    |
// |----+----+----+----+----+----|              |----+----+----+----+----+----|
// |    |    |    |    |    |    |              |    |    |    |    |    |    |
// |----+----+----+----x----x----|              |----x----x----+----+----+----|
// |    |    |    |    |    |    |              |    |    |    |    |    |    |
// |----+----+----+----x----x----+----.    ,----|----x----x----+----+----+----|
// |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
// `-------------------+----+----+----/    \----+----+----+-------------------'
//                    |    |    |    |      |    |    |    |
//                    `----+---------'      `--------------'


#include QMK_KEYBOARD_H
#include "pvinis.h"
//#include "iris.h"
//#include "action_layer.h"
//#include "eeconfig.h"

#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

#ifdef AUDIO_ENABLE
  //#define STARTUP_SONG SONG(SONIC_RING)
#endif

#ifdef AUDIO_ENABLE
float tone_sonic[][2] = SONG(IN_LIKE_FLINT);
float tone_1[][2] = SONG(QWERTY_SOUND);
float tone_2[][2] = SONG(OLD_SPICE);
float tone_3[][2] = SONG(OVERWATCH_THEME);
float tone_4[][2] = SONG(QWERTY_SOUND);
#endif




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // ,-----------------------------.              ,-----------------------------.
  // | `  |    |    |    |    |QWER|              |    |    |    |    |    | "  |
  // |----+----+----+----+----+----|              |----+----+----+----+----+----|
  // |Tab |    |    |    |    |CARP|              |    |    |    |    |    |Del |
  // |----+----+----+----x----x----|              |----x----x----+----+----+----|
  // |EscC|    |    |    |    |    |              |    |    |    |    |    |Ent |
  // |----+----+----+----x----x----+----.    ,----|----x----x----+----+----+----|
  // |LSft|    |    |    |    |    |Home|    |End |    |    |    |    |    |Rsft|
  // `-------------------+----+----+----/    \----+----+----+-------------------'
  //                    |Cmd |LOWR|Bspc|      |Spc |RASE|RAlt|
  //                    `----+---------'      `--------------'
  [LR_BASE] = LAYOUT_wrapper(
    KC_GRV , _______, _______, _______, _______, QWERTY ,                       _______, _______, _______, _______, _______, KC_QUOT,
    KC_TAB , _______, _______, _______, _______, CARPALX,                       _______, _______, _______, _______, _______, KC_DEL ,
    PV_ESCC, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_ENT ,
    KC_LSFT, _______, _______, _______, _______, _______, KC_HOME,      KC_END, _______, _______, _______, _______, _______, KC_RSFT,
                                        KC_LGUI, LOWER  , KC_BSPC,      KC_SPC, RAISE  , KC_RALT
  ),

  // ,-----------------------------.              ,-----------------------------.
  // |    |       NUMBERS_L        |              |         NUMBERS_R      |    |
  // |----+----+----+----+----+----|              |----+----+----+----+----+----|
  // |    |                        |              |                        |    |
  // |----+                        |              |                        +----|
  // |    |       QWERTY_L         |              |         QWERTY_R       |    |
  // |----+                        +----.    ,----|                        +----|
  // |    |                        |    |    |    |                        |    |
  // `-------------------+----+----+----/    \----+----+----+-------------------'
  //                    |    |    |    |      |    |    |    |
  //                    `----+---------'      `--------------'
  [LR_QWERTY] = LAYOUT_wrapper(
    _______, ________________NUMBERS_L__________________,                        ________________NUMBERS_R__________________, _______,
    _______, _________________QWERTY_L1_________________,                        _________________QWERTY_R1_________________, _______,
    _______, _________________QWERTY_L2_________________,                        _________________QWERTY_R2_________________, _______,
    _______, _________________QWERTY_L3_________________, _______,      _______, _________________QWERTY_R3_________________, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),

  // ,-----------------------------.              ,-----------------------------.
  // |    |       NUMBERS_L        |              |         NUMBERS_R      |    |
  // |----+----+----+----+----+----|              |----+----+----+----+----+----|
  // |    |                        |              |                        |    |
  // |----+                        |              |                        +----|
  // |    |      CARPALX_L         |              |        CARPALX_R       |    |
  // |----+                        +----.    ,----|                        +----|
  // |    |                        |    |    |    |                        |    |
  // `-------------------+----+----+----/    \----+----+----+-------------------'
  //                    |    |    |    |      |    |    |    |
  //                    `----+---------'      `--------------'
  [LR_CARPALX] = LAYOUT_wrapper(
    _______, ________________NUMBERS_L__________________,                        ________________NUMBERS_R__________________, _______,
    _______, ________________CARPALX_L1_________________,                        ________________CARPALX_R1_________________, _______,
    _______, ________________CARPALX_L2_________________,                        ________________CARPALX_R2_________________, _______,
    _______, ________________CARPALX_L3_________________, _______,      _______, ________________CARPALX_R3_________________, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),

  [LR_LOWER] = LAYOUT_wrapper(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                        KC_CIRC, KC_AMPR, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_LBRK, KC_RBRK,                        KC_SLSH, KC_7   , KC_8   , KC_9   , _______, _______,
    _______, _______, _______, KC_PLUS, KC_LPRN, KC_RPRN,                        KC_EQL , KC_4   , KC_5   , KC_6   , _______, KC_PIPE,
    _______, _______, _______, KC_MINS, KC_LBRC, KC_RBRC, _______,      _______, KC_ASTR, KC_1   , KC_2   , KC_3   , _______, _______,
                                        _______, _______, _______,      _______, _______, KC_0
  ),

  [LR_RAISE] = LAYOUT_wrapper(
    KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
    KC_AMPR, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                        KC_MUTE, KC_HOME, KC_UP  , KC_END , KC_RPRN, _______,
    KC_LPRN, KC_MPRV, KC_MNXT, KC_CIRC, KC_PGUP, KC_UNDS,                        KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT, KC_ASTR, KC_BSLS,
    KC_PLUS, KC_MSTP, KC_MPLY, KC_EQL , KC_PGDN, KC_MINS, _______,      _______, KC_VOLD, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),

  [LR_ADJUST] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  )
};

// void persistent_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }

// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         persistent_default_layer_set(1UL<<_QWERTY);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case ADJUST:
//       if (record->event.pressed) {
//         layer_on(_ADJUST);
//       } else {
//         layer_off(_ADJUST);
//       }
//       return false;
//       break;
//     case SSP:
//       #ifdef AUDIO_ENABLE
//       if (record->event.pressed) {
//         PLAY_SONG(tone_sonic);
//       }
//       #endif
//       return false;
//     case SSP1:
//       #ifdef AUDIO_ENABLE
//       if (record->event.pressed) {
//         PLAY_SONG(tone_1);
//       }
//       #endif
//       return false;
//     case SSP2:
//       #ifdef AUDIO_ENABLE
//       if (record->event.pressed) {
//         PLAY_SONG(tone_2);
//       }
//       #endif
//       return false;
//     case SSP3:
//       #ifdef AUDIO_ENABLE
//       if (record->event.pressed) {
//         PLAY_SONG(tone_3);
//       }
//       #endif
//       return false;
//     case SSP4:
//       #ifdef AUDIO_ENABLE
//       if (record->event.pressed) {
//         PLAY_SONG(tone_4);
//       }
//       #endif
//       return false;
//   }
//   return true;
// }
