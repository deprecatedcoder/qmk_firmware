/**
 * Boardy keymap by @deprecatedcoder
 *
 * Custom layout
 *
 * Unicode requires WinCompose:
 *  > https://github.com/samhocevar/wincompose/releases
 */

#include QMK_KEYBOARD_H
#include "action_layer.h"


// Keyboard Layers
enum keyboard_layers {
    _BASE = 0,    // Base Layer
    _FUNCTION,    // Function Layer
    _LIGHTING,    // Lighting Layer
    _ADVFUNC,     // Advanced Function Layer
};


// Custom Keycodes
enum custom_keycodes {
    // Three Finger Salute: Ctl-Alt-Del
    TFS = LCTL(LALT(KC_DEL)),
};


// Tap Dance Actions
enum tap_dance_actions{
    TD_LAYER = 0,
    TD_SHRUG = 1,
};


// Tap Dance States
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP
} td_state_t;

static td_state_t td_state;


// Function Declarations
int cur_dance (qk_tap_dance_state_t *state);
void layers_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void layers_dance_reset(qk_tap_dance_state_t *state, void *user_data);
void shrug_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void shrug_dance_reset(qk_tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_FUNCTION] = LAYOUT(
  /*
    1: Function Layer
    ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
    │ ~      │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │ `      │ F1     │ F2     │ F3     │ F4     │ F5     │ F6     │ F7     │ F8     │ F9     │ F10    │ F11    │ F12    │ Delete          │
    ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │            │        │        │        │ RGB    │ RGB    │ RGB    │ RGB    │        │        │        │        │        │             │
    │ Num Lock   │ 7      │ 8      │ 9      │ Toggle │ Mode   │ Pwr+   │ Pwr-   │ Insert │ Calc   │ Pause  │ Home   │ End    │ TFS         │
    ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │ RGB    │ RGB    │ RGB    │ RGB    │        │        │ Page   │ Page   │                   │
    │ Caps Lock     │ 4      │ 5      │ 6      │ Hue+   │ Hue-   │ Sat+   │ Sat-   │        │ Toggle │ Up     │ Down   │ Shift             │
    ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
    │                   │        │        │        │ Back   │        │        │ Back   │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │ Light  │ Back   │ Back   │ Light  │ Prev   │ Next   │        │ ░░░░ │ Vol    │ ░░░░░░ │
    │ Shift             │ 1      │ 2      │ 3      │ Toggle │ Light+ │ Light- │ Breathe│ Track  │ Track  │ Reset  │ ░░░░ │ Up     │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │          │ ░░░░ │        │ Vol    │        │
    │ Ctrl     │ Win      │ Alt      │ 0                                                      │ Func     │ ░░░░ │ Mute   │ Down   │ Right  │
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘
  */

  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_NO,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
     KC_NLCK,     KC_P7,   KC_P8,   KC_P9,   RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, KC_INS,  KC_CALC, KC_PAUS, KC_HOME, KC_END,  TFS,
  //├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
     KC_CLCK,        KC_P4,   KC_P5,   KC_P6,   RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_NO,   NK_TOGG, KC_PGUP, KC_PGDN, KC_NO, KC_RSFT,
  //├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
     KC_LSFT, KC_NO,     KC_P1,   KC_P2,   KC_P3,   BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG, KC_MPRV, KC_MNXT, RESET,   KC_NO, KC_VOLU, KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     _______,   _______,   _______,   KC_P0,                                                   _______,   KC_NO, KC_MUTE, KC_VOLD, KC_MPLY),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘


  [_BASE] = LAYOUT(
  /*
    0: Base Layer
    ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
    │ ~      │ !      │ @      │ #      │ $      │ %      │ ^      │ &      │ *      │ (      │ )      │ _      │ +      │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │ Esc    │ 1      │ 2      │ 3      │ 4      │ 5      │ 6      │ 7      │ 8      │ 9      │ 0      │ -      │ =      │ Backspace       │
    ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
    │            │        │        │        │        │        │        │        │        │        │        │ {      │ ]      │ │           │
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │ Tab        │ Q      │ W      │ E      │ R      │ T      │ Y      │ U      │ I      │ O      │ P      │ [      │ ]      │ \           │
    ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
    │               │        │        │        │        │        │        │        │        │        │ :      │ "      │                   │
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │ PrntScr       │ A      │ S      │ D      │ F      │ G      │ H      │ J      │ K      │ L      │ ;      │ '      │ Enter             │
    ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
    │                   │        │        │        │        │        │        │        │ <      │ >      │ ?      │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │ Shift/SHRUG       │ Z      │ X      │ C      │ V      │ B      │ N      │ M      │ ,      │ .      │ /      │ ░░░░ │ Up     │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │ Ctrl     │ Win      │ Alt      │ Space                                                  │ Layers   │ ░░░░ │ Left   │ Down   │ Right  │
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘
  */

  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
     KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
  //├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
     KC_PSCR,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO, KC_ENT,
  //├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
     TD(TD_SHRUG), KC_NO, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, KC_UP,   KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     KC_LCTL,   KC_LGUI,   KC_LALT,   KC_SPC,                                                TD(TD_LAYER), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘

  };


// Loop
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _BASE:
            // Set breathing period to default
            if (get_breathing_period() != BREATHING_PERIOD) {
                breathing_period_default();
            }
            // Set underglow to snake-mode (counterclockwise)
            if (rgblight_get_mode() != RGBLIGHT_MODE_SNAKE+1) {
                rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE+1);
            }
            break;
        case _FUNCTION:
            // Set the breathing period faster and faster
            if (get_breathing_period() > 1) {
                breathing_period_set(get_breathing_period() - 1);
            }
            // Set backlight to max
            // backlight_level(BACKLIGHT_LEVELS);
            // Set underglow to breathing-mode (fast)
            if (rgblight_get_mode() != RGBLIGHT_MODE_BREATHING+3) {
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
                rgblight_set_speed_noeeprom(255);
            }
            break;
    }
};


// Set the Tap Dance state
int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }
    if (state->count == 2) return DOUBLE_TAP;
    else return 3;
}


/**
 *  Layer Tap Dance functions
 *
 *  1: _FUNCTION layer
 */
void layers_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            layer_move(_FUNCTION);
            break;
        case 2:
            // SEND_STRING("TEST");
            // layer_move(_LIGHTING);
            break;
        case 3:
            // layer_move(_ADVFUNC);
            break;
        default:
            break;
    }
}
void layers_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    layer_move(_BASE);
}


/**
 *  ¯\_(ツ)_/¯ Tap Dance functions
 *
 *  - Tap: OneShot SHIFT
 *  - Hold: SHIFT
 *  - 2: ¯\_(ツ)_/¯
 */
void shrug_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);

    switch(td_state) {
        case SINGLE_TAP:
            set_oneshot_mods(MOD_LSFT);
            break;
        case SINGLE_HOLD:
            register_code (KC_LSFT);
            break;
        case DOUBLE_TAP:
            // ¯\_(ツ)_/¯
            send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            break;
        default:
            break;
    }
}
void shrug_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            clear_oneshot_mods();
            break;
        case SINGLE_HOLD:
            unregister_code (KC_LSFT);
            break;
        default:
            break;
    }
}


// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, layers_dance_finished, layers_dance_reset),
    [TD_SHRUG] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shrug_dance_finished, shrug_dance_reset),
};
