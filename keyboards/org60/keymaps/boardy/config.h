#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// Boardy is a bit special and has some wires crossed, so needs these redefined
//
// For more details, see: https://www.reddit.com/r/MechanicalKeyboards/comments/6xsd5c/
//
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { F0, F1, E6, C7, C6, B6, D4, B1, B7, F5, B4, D7, D6, B3 }

#undef BACKLIGHT_PIN
#define BACKLIGHT_PIN B5

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 12

#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 8

#define UNICODE_SELECTED_MODES UC_WINC

/* key combination for magic key command */
#define IS_COMMAND() ( \
  keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#endif // CONFIG_USER_H
