#include QMK_KEYBOARD_H
#include "action_layer.h"

// Keyboard Layers
enum keyboard_layers {
  _BASE,        // Base Layer
  _FUNCTION,    // Function Layer
};

enum custom_keycodes {
    SHRUG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
    │ Shift             │ Z      │ X      │ C      │ V      │ B      │ N      │ M      │ ,      │ .      │ /      │ ░░░░ │ Up     │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │ Ctrl     │ Win      │ Alt      │ Space                                                  │ FnO      │ ░░░░ │ Left   │ Down   │ Right  │
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
     KC_LSFT, KC_NO,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, KC_UP,   KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     KC_LCTL,   KC_LGUI,   KC_LALT,   KC_SPC,                                               MO(_FUNCTION),KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘


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
    │ Reset      │ 7      │ 8      │ 9      │ Toggle │ Mode   │ Pwr+   │ Pwr-   │        │ Insert │ Pause  │ Home   │ End    │ Sleep       │
    ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │ RGB    │ RGB    │ RGB    │ RGB    │        │        │ Page   │ Page   │                   │
    │ Caps Lock     │ 4      │ 5      │ 6      │ Hue+   │ Hue-   │ Sat+   │ Sat-   │        │        │ Up     │ Down   │ Shift             │
    ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
    │                   │        │        │        │ Back   │        │        │ Back   │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │ Light  │ Back   │ Back   │ Light  │ Prev   │ Next   │        │ ░░░░ │        │ ░░░░░░ │
    │ SHRUG             │ 1      │ 2      │ 3      │ Toggle │ Light+ │ Light- │ Breathe│ Track  │ Track  │        │ ░░░░ │ Up     │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │ Ctrl     │ Win      │ Alt      │ 0                                                      │ Fn0      │ ░░░░ │ Mute   │ Down   │ Right  │
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘
  */

  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
     KC_GRAVE,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_NO,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
     RESET,       KC_7,    KC_8,    KC_9,    RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, KC_NO,   KC_INS,  KC_PAUS, KC_HOME, KC_END,  KC_SLEP,
  //├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
     KC_CAPS,        KC_4,    KC_5,    KC_6,    RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_NO,   KC_NO,   KC_PGUP, KC_PGDN, KC_NO, KC_RSFT,
  //├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
     SHRUG,   KC_NO,     KC_1,    KC_2,    KC_3,    BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG,   KC_MPRV, KC_MNXT, KC_NO,   KC_NO, KC_VOLU, KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     KC_LCTL,   KC_LGUI,   KC_LALT,   KC_0,                                                 MO(_FUNCTION),KC_NO, KC_MUTE, KC_VOLD, KC_MPLY),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case SHRUG: // ¯\_(ツ)_/¯
                if (record->event.pressed) {
                    send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
                }
                return false;
                break;
        }
    }
    return true;
}

// Loop
void matrix_scan_user(void) {
  // Empty
};
