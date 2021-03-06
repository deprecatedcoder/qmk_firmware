#ifndef CONFIG_USER_H
#define CONFIG_USER_H


#include "../../config.h"


/*** OVERRIDES ***/

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 12

#undef DEBOUNCE
#define DEBOUNCE 10

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY


/*** CUSTOM DEFINES ***/

#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 8
#define FORCE_NKRO
#define UNICODE_SELECTED_MODES UC_WINC


#endif // CONFIG_USER_H
