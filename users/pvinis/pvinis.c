#include "pvinis.h"
#include "version.h"


#ifdef AUDIO_ENABLE
#    include "audio.h"

float song_sonic_ring[][2] = SONG(SONIC_RING);
float song_coin_sound[][2] = SONG(COIN_SOUND);
float song_test[][2]       = SONG(QWERTY_SOUND);
#endif

#ifdef RGBLIGHT_ENABLE

bool showing_knight = false;

#endif


// SYMBOL + SYSCTL = KBCTL
uint32_t layer_state_set_user(uint32_t state) {
    uint32_t intermediate_state = update_tri_layer_state(state, LR_SYMBOL, LR_SYSCTL, LR_KBCTL);
    intermediate_state          = layer_state_set_user_keymap(intermediate_state);
    return intermediate_state;
}


// functions for the individual keymaps to implement if they need something extra
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }


// Handle my own keycodes.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PV_HMDP:
            SEND_STRING("LETSGO");
            return false;

        case PV_VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;

        case PV_CMPL:
            if (!record->event.pressed) {
                SEND_STRING("qmk compile --keyboard " QMK_KEYBOARD " --keymap " QMK_KEYMAP SS_TAP(X_ENTER));
            }
            return false;

        case PV_MAKE:
            if (!record->event.pressed) {
                SEND_STRING("qmk flash --keyboard " QMK_KEYBOARD " --keymap " QMK_KEYMAP SS_TAP(X_ENTER));
            }
            return false;

        case PV_RST:
            reset_keyboard();
            return false;

        case PV_SSNC:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(song_sonic_ring);
#endif
            }
            return false;

        case PV_SCIN:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(song_coin_sound);
#endif
            }
            return false;

        case PV_TEST:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(song_test);
#endif
            }
            return false;

        case PV_L_KNTTGL:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                // if (showing_knight) {
                //     rgblight_sethsv(HSV_RED);
                //     rgblight_mode(RGBLIGHT_MODE_KNIGHT + 2);
                // } else {
                //     rgblight_sethsv(HSV_BLACK);
                //     rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                // }
                // showing_knight = !showing_knight;
#endif
            }
            return false;
    }
    return process_record_keymap(keycode, record);
}

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {};
#endif

void keyboard_post_init_rgb_light(void) {
#ifdef RGBLIGHT_ENABLE
#endif
}

// Init stuff.
void keyboard_post_init_user(void) {
    keyboard_post_init_rgb_light();
    keyboard_post_init_user_keymap();
}


// Default functions.
__attribute__((weak)) void keyboard_post_init_user_keymap(void) {}

__attribute__((weak)) uint32_t layer_state_set_user_keymap(uint32_t state) { return state; }
