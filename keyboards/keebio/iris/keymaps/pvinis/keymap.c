// pvinis iris
// make keebio/iris/rev2:pvinis:avrdude
// ,-----------------------------.              ┌────┬────┬────┬────┬────┬────┐
// |    |    |    |    |    |    |              │    │    │    │    │    │    │
// |----+----+----+----+----+----|              ├────┼────┼────┼────┼────┼────┤
// |    |    |    |    |    |    |              │    │    │    │    │    │    │
// |----+----+----+----x----x----|              ├────╆━━━━╅────┼────┼────┼────┤
// |    |    |    |    |    |    |              │    ┃    ┃    │    │    │    │
// |----+----+----+----x----x----+----.    ┌────┼────╄━━━━╃────┼────┼────┼────┤
// |    |    |    |    |    |    |    |    │    │    │    │    │    │    │    │
// `-------------------+----+----+----/    └┬───┴┬───┴┬───┴┬───┴────┴────┴────┘
//                    |    |    |    |      │    │    │    │
//                    `----+---------'      └────┴────┴────┘


#include QMK_KEYBOARD_H
#include "pvinis.h"
//#include "iris.h"
//#include "action_layer.h"
//#include "eeconfig.h"

#ifdef AUDIO_ENABLE
    #include "audio.h"
#endif

#ifdef AUDIO_ENABLE
//   #define STARTUP_SONG SONG(SONIC_RING)
#endif

#ifdef AUDIO_ENABLE
//   float n04[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
//   float n10[][2] = SONG(STARTUP_SOUND);
//   float n11[][2] = SONG(GOODBYE_SOUND);
//   float n12[][2] = SONG(PLANCK_SOUND);
//   float n19[][2] = SONG(MUSIC_ON_SOUND);
//   float n20[][2] = SONG(AUDIO_ON_SOUND);
//   float n29[][2] = SONG(CAPS_LOCK_ON_SOUND);
//   float n30[][2] = SONG(CAPS_LOCK_OFF_SOUND);
//   float n31[][2] = SONG(SCROLL_LOCK_ON_SOUND);
//   float n32[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
//   float n33[][2] = SONG(NUM_LOCK_ON_SOUND);
//   float n34[][2] = SONG(NUM_LOCK_OFF_SOUND);
//   float n40[][2] = SONG(ONE_UP_SOUND);
//   float n49[][2] = SONG(E1M1_DOOM);
//   float n53[][2] = SONG(OLD_SPICE);
//   float n56[][2] = SONG(RICK_ROLL);
//   float n57[][2] = SONG(FF_PRELUDE);
// RGB_MODE_KNIGHT
//   float n78[][2] = SONG(KATAMARI_ROLLING_STAR);
    float song_qwerty[][2] = SONG(QWERTY_SOUND);
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ,-----------------------------.              ,-----------------------------.
    // |    |    |    |    |GAME|QWER|              |    |    |    |    |    |    |
    // |----+----+----+----+----+----|              |----+----+----+----+----+----|
    // |Tab |    |    |    |    |CRPL|              |    |    |    |    |    |Del |
    // |----+----+----+----x----x----|              |----x----x----+----+----+----|
    // |EscC|    |    |    |    |    |              |    |    |    |    |    |Ent |
    // |----+----+----+----x----x----+----.    ,----|----x----x----+----+----+----|
    // |LSft|    |    |    |    |    |Home|    |End |    |    |    |    |    |Rsft|
    // `-------------------+----+----+----/    \----+----+----+-------------------'
    //                    |Cmd |LOWR|Bspc|      |Spc |RASE|RAlt|
    //                    `----+---------'      `--------------'
    [LR_BASE] = LAYOUT_wrapper(
        // clang-format off
        KC_MUTE, _______, _______, _______, GAME1  , QWERTY ,                        KC_1   , _______, _______, _______, _______, _______,
        KC_TAB , ___________________________________________,                        ___________________________________________, KC_DEL ,
        PV_ESCC, ___________________________________________,                        ___________________________________________, KC_ENT ,
        KC_LSFT, ___________________________________________, _______,      _______, _______, _______, _______, _______, _______, KC_RSFT,
                                            KC_LGUI, SYMBOL , KC_BSPC,      KC_SPC , SYSCTL , SYSCTL2
        // clang-format on
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
        // clang-format off
        _______, ________________NUMBERS_L__________________,                        ________________NUMBERS_R__________________, _______,
        _______, _________________QWERTY_L1_________________,                        _________________QWERTY_R1_________________, _______,
        _______, _____________MOD_QWERTY_L2_________________,                        _________________QWERTY_R2_________________, _______,
        _______, _________________QWERTY_L3_________________, _______,      _______, _________________QWERTY_R3_________________, _______,
                                            _______, _______, _______,      _______, _______, _______
        // clang-format on
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
        // clang-format off
        _______, ________________NUMBERS_L__________________,                        ________________NUMBERS_R__________________, _______,
        _______, ________________CARPALX_L1_________________,                        ________________CARPALX_R1_________________, _______,
        _______, ________________CARPALX_L2_________________,                        ________________CARPALX_R2_________________, _______,
        _______, ________________CARPALX_L3_________________, _______,      _______, ________________CARPALX_R3_________________, _______,
                                            _______, _______, _______,      _______, _______, _______
        // clang-format on
        ),

    [LR_SYMBOL] = LAYOUT_wrapper(
        // clang-format off
        KC_F12 , ______________________F_L__________________,                        ______________________F_R__________________, KC_F11 ,
        _______, _________________SYMBOL_L1_________________,                        _________________SYMBOL_R1_________________, _______,
        _______, _________________SYMBOL_L2_________________,                        _________________SYMBOL_R2_________________, _______,
        _______, _________________SYMBOL_L3_________________, _______,      _______, _________________SYMBOL_R3_________________, _______,
                                            _______, _______, _______,      _______, _______, _______
        // clang-format on
        ),

    [LR_SYSCTL] = LAYOUT_wrapper(
        // clang-format off
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
        _______, _________________SYSCTL_L1_________________,                        _________________SYSCTL_R1_________________, _______,
        _______, _________________SYSCTL_L2_________________,                        _________________SYSCTL_R2_________________, _______,
        _______, _________________SYSCTL_L3_________________, _______,      _______, _________________SYSCTL_R3_________________, _______,
                                            _______, _______, _______,      _______, _______, _______
        // clang-format on
        ),

    [LR_SYSCTL2] = LAYOUT_wrapper(
        // clang-format off
        _______, ___________________________________________,                        ___________________________________________, _______,
        _______, ___________________________________________,                        ___________________________________________, _______,
        _______, ___________________________________________,                        ___________________________________________, _______,
        _______, ___________________________________________, _______,      _______, ________________SYSCTL2_R3_________________, _______,
                                            _______, _______, _______,      _______, _______, _______
        // clang-format on
        ),

    [LR_KBCTL] = LAYOUT_wrapper(
        // clang-format off
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, __________________KBCTL_L1_________________,                        __________________KBCTL_R1_________________, XXXXXXX,
        XXXXXXX, __________________KBCTL_L2_________________,                        __________________KBCTL_R2_________________, XXXXXXX,
        BASE   , __________________KBCTL_L3_________________, XXXXXXX,      XXXXXXX, __________________KBCTL_R3_________________, XXXXXXX,
                                            XXXXXXX, _______, XXXXXXX,      XXXXXXX, _______, XXXXXXX
        // clang-format on
        ),

    [LR_WARZONE] = LAYOUT_wrapper(
        // clang-format off
        _______, ________________NUMBERS_L__________________,                        ________________NUMBERS_R__________________, _______,
        _______, _________________QWERTY_L1_________________,                        _________________QWERTY_R1_________________, _______,
        KC_LCTL, _________________QWERTY_L2_________________,                        _________________QWERTY_R2_________________, _______,
        _______, _________________QWERTY_L3_________________, KC_LWIN,      _______, _________________QWERTY_R3_________________, _______,
                                            KC_M   , KC_SPC , KC_LALT,      _______, _______, _______
        // clang-format on
        ),

    [LR_GAME2] = LAYOUT_wrapper(
        // clang-format off
        _______, ________________NUMBERS_L__________________,                        ________________NUMBERS_R__________________, KC_BSPC,
        _______, _________________QWERTY_L1_________________,                        KC_Y   , KC_U   , KC_UP  , KC_O   , KC_P   , QWERTY ,
        KC_ESC , _________________QWERTY_L2_________________,                        KC_H   , KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, _______,
        _______, _________________QWERTY_L3_________________, _______,      _______, _________________QWERTY_R3_________________, _______,
                                            _______, _______, KC_SPC ,      _______, _______, _______
        // clang-format on
        ),
};


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(LR_WARZONE)) {
        tap_code(KC_ESC);
        return;
    }

    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}
#endif


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        #ifdef AUDIO_ENABLE
            // case PV_S04: if (record->event.pressed) PLAY_SONG(n04); return false; break;
        #endif
    }
    return true;  // Process everything else normally
}


// keyboard initialization
void keyboard_post_init_user_keymap(void) {
    // run on qwerty by default, after base is inited
    layer_on(LR_QWERTY);
    #ifdef AUDIO_ENABLE
        PLAY_SONG(song_qwerty);
    #endif
}
