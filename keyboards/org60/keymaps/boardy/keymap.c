/**
 * Boardy keymap by @deprecatedcoder
 *
 * Unicode functions require WinCompose:
 *  > https://github.com/samhocevar/wincompose/releases
 */

#include QMK_KEYBOARD_H
#include "action_layer.h"


// Custom Keycodes
enum custom_keycodes {
    // WinCompose URL
    WINCMPS = SAFE_RANGE,
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


// Layer Declarations
enum keyboard_layers {
    _BASE = 0,    // Base Layer
    _FUNCTION,    // Function Layer
    _LIGHTING,    // Lighting Layer
    _ADVFUNC,     // Advanced Function Layer
};


// Layer Definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* [_BLANK] = LAYOUT(
  / * XX: Blank Layer
    ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │ Layers   │ ░░░░ │        │        │        │
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘  * /

  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
     KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
     KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  //├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
     KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                                   _______,   KC_NO, KC_NO,   KC_NO,   KC_NO),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘
  */

  [_ADVFUNC] = LAYOUT(
  /* 3: Advanced Function Layer
    ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │ Sleep  │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │ Reset      │        │        │        │        │        │        │        │        │        │        │        │        │             │
    ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │ WinCompose URL                                         │ Layers   │ ░░░░ │        │        │        │
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘  */

  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
     KC_SLEP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
     RESET,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
     KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  //├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
     KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     KC_NO,     KC_NO,     KC_NO,     WINCMPS,                                                 _______,   KC_NO, KC_NO,   KC_NO,   KC_NO),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘


  [_LIGHTING] = LAYOUT(
  /* 2: Lighting Layer
    ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │            │        │        │        │ RGB    │ RGB    │ RGB    │ RGB    │        │        │        │        │        │             │
    │            │        │        │        │ Toggle │ Mode   │ Pwr+   │ Pwr-   │        │        │        │        │        │             │
    ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │ RGB    │ RGB    │ RGB    │ RGB    │        │        │        │        │                   │
    │               │        │        │        │ Hue+   │ Hue-   │ Sat+   │ Sat-   │        │        │        │        │                   │
    ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │ Back   │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │ Light  │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │ +      │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │ Back   │ Back   │ Back   │
    │          │          │          │                                                        │          │ ░░░░ │ Light  │ Light  │ Light  │
    │          │          │          │                                                        │ Layers   │ ░░░░ │ Breathe│ -      │ Toggle │
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘  */

  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   BL_TOGG, BL_DEC,  BL_INC,  BL_BRTG, KC_NO,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
     KC_NO,       KC_NO,   KC_NO,   KC_NO,   RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
     KC_NO,          KC_NO,   KC_NO,   KC_NO,   RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  //├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
     KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, BL_INC,  KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                                   _______,   KC_NO, BL_BRTG, BL_DEC,  BL_TOGG),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘


  [_FUNCTION] = LAYOUT(
  /* 1: Function Layer
    ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
    │ ~      │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
    │ `      │ F1     │ F2     │ F3     │ F4     │ F5     │ F6     │ F7     │ F8     │ F9     │ F10    │ F11    │ F12    │ Delete          │
    ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
    │            │        │        │        │        │        │        │        │        │        │        │        │        │             │
    │            │        │        │        │        │        │        │        │        │        │ Page   │        │        │             │
    │ Num Lock   │ 7      │ 8      │ 9      │        │        │        │        │ Insert │ Calc   │ Up     │ Home   │ End    │ TFS         │
    ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
    │               │        │        │        │        │        │        │        │        │        │        │        │                   │
    │               │        │        │        │        │        │        │        │        │        │ Page   │        │                   │
    │ Caps Lock     │ 4      │ 5      │ 6      │        │        │        │        │        │        │ Down   │ Pause  │ Enter             │
    ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
    │                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
    │                   │        │        │        │        │        │        │        │ Prev   │ Next   │        │ ░░░░ │ Vol    │ ░░░░░░ │
    │ Shift             │ 1      │ 2      │ 3      │        │        │        │        │ Track  │ Track  │ .      │ ░░░░ │ Up     │ ░░░░░░ │
    ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
    │          │          │          │                                                        │          │ ░░░░ │        │        │        │
    │          │          │          │                                                        │          │ ░░░░ │        │ Vol    │        │
    │ Ctrl     │ Win      │ Alt      │ 0                                                      │ Layers   │ ░░░░ │ Mute   │ Down   │ Right  │
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘  */

  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
  //│        │        │        │        │        │        │        │        │        │        │        │        │        │                 │
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_NO,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
  //│            │        │        │        │        │        │        │        │        │        │        │        │        │             │
     KC_NLCK,     KC_P7,   KC_P8,   KC_P9,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_CALC, KC_PGUP, KC_HOME, KC_END,  TFS,
  //├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
  //│               │        │        │        │        │        │        │        │        │        │        │        │                   │
     KC_CLCK,        KC_P4,   KC_P5,   KC_P6,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_PAUS, KC_NO, _______,
  //├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴─┬────────┬────────┤
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
  //│                   │        │        │        │        │        │        │        │        │        │        │ ░░░░ │        │ ░░░░░░ │
     KC_LSFT, KC_NO,     KC_P1,   KC_P2,   KC_P3,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_DOT,  KC_NO, KC_VOLU, KC_NO,
  //├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴────────┼──────┬─┴──────┼────────┼────────┤
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
  //│          │          │          │                                                        │          │ ░░░░ │        │        │        │
     _______,   _______,   _______,   KC_P0,                                                   _______,   KC_NO, KC_MUTE, KC_VOLD, KC_MPLY),
  //└──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘


  [_BASE] = LAYOUT(
  /* 0: Base Layer
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
    └──────────┴──────────┴──────────┴────────────────────────────────────────────────────────┴──────────┴──────┴────────┴────────┴────────┘  */

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


// Custom key handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WINCMPS:
            if (record->event.pressed) {
                // Output WinCompose URL
                SEND_STRING("https://github.com/samhocevar/wincompose/releases");
            }
            break;
        }

    return true;
};


// Actions on layer state change
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
       case _BASE:
            if (!is_breathing() || get_breathing_period() != BREATHING_PERIOD) {
                // Enable breathing
                breathing_enable();
                // Set breathing period to default
                breathing_period_default();
            }
            if (rgblight_get_mode() != RGBLIGHT_MODE_SNAKE+1) {
                // Set underglow to snake-mode (counterclockwise)
                rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE+1);
            }
            break;
        case _FUNCTION:
            if (!is_breathing() || get_breathing_period() != (BREATHING_PERIOD/2)) {
                // Enable breathing
                breathing_enable();
                // Set the breathing period twice as fast as normal
                breathing_period_set(BREATHING_PERIOD/2);
            }
            if (rgblight_get_mode() != RGBLIGHT_MODE_BREATHING+3) {
                // Set underglow to breathing-mode (fast)
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
                rgblight_set_speed_noeeprom(255);
            }
            break;
        case _LIGHTING:
            if (is_breathing()) {
                // Disable breathing
                breathing_disable();
                // Set backlight to max
                backlight_level(BACKLIGHT_LEVELS);
            }
            break;
        case _ADVFUNC:
            if (!is_breathing() || get_breathing_period() != 1) {
                // Enable breathing
                breathing_enable();
                // Set the breathing period to fast
                breathing_period_set(1);
            }
            break;
        default:
            break;
    }

    return state;
};


// Set power down behavior
void suspend_power_down_user(void) {
    backlight_disable();
    rgblight_disable_noeeprom();
}

// Set wake up behavior
void suspend_wakeup_init_user(void) {
    backlight_enable();
    rgblight_enable_noeeprom();
}


// Set the Tap Dance state
int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->finished && (state->interrupted || !state->pressed)) return SINGLE_TAP;
        else if (state->finished) return SINGLE_HOLD;
    }
    if (state->count == 2) return DOUBLE_TAP;
    else return 3;
}


/**
 *  Layer Tap Dance functions
 *
 *  1: _FUNCTION layer
 *      * General functions (Fkeys, *Locks. etc)
 *      * NumPad
 *      * Media controls
 *      * Calculator launch
 *      * TFS (Ctrl+Alt+Del)
 *  2: _LIGHTING
 *      * LED key backlight controls
 *      * RGB underglow controls
 *  3: _ADVFUNC
 *      * Sleep
 *      * Enter bootloader mode
 *      * Ouput WinCompose URL
 */
void layers_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            layer_move(_FUNCTION);
            break;
        case 2:
            layer_move(_LIGHTING);
            break;
        case 3:
            layer_move(_ADVFUNC);
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
