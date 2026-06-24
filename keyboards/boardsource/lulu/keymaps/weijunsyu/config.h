#pragma once

/* Select hand configuration */
//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

/* Split Keyboard configuration */
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

/* Define startup configuration */ /* USB detection used as rp2040 does not support VBUS detection. */
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_WATCHDOG_ENABLE /* This will enable a software watchdog on any side delegated as slave and will reboot the keyboard if no successful communication occurs within SPLIT_WATCHDOG_TIMEOUT */
#define SPLIT_WATCHDOG_TIMEOUT 2500
#ifdef NKRO_ENABLE
    //#define NKRO_DEFAULT_ON /* Set NKRO on by default. May cause issues with legacy USB protocols. */
    //#define FORCE_NKRO /* Force NKRO always on. May cause issues with legacy USB protocols. */
#endif

/* Define global tapping configuration */
#define TAP_CODE_DELAY 10  /* Sets the delay (ms) between register_code and unregister_code (blocking). Default: 0. */
//#define QUICK_TAP_TERM 120
#define QUICK_TAP_TERM_PER_KEY
#define TAPPING_TERM 200
#define ONESHOT_TAP_TOGGLE 0  /* Tapping this number of times holds the key until tapped once again. 0 to disable. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */
//#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#ifdef COMBO_ENABLE
    #define COMBO_TERM 15
    #define COMBO_MUST_HOLD_MODS  /* If a combo triggers a modifier, only trigger when the combo is held. */
    #define COMBO_HOLD_TERM 175  /* How long at least one of the combo keys must be held to trigger as a HOLD action. */
#endif
#ifdef CAPS_WORD_ENABLE
    #define CAPS_WORD_INVERT_ON_SHIFT /* Do not turn off Caps Word on shift; instead, invert key. */
    #define CAPS_WORD_IDLE_TIMEOUT 0  /* Time (in ms) before Caps Word turns off. 0 to never timeout. */
#endif

/* Mouse Keys: */
#ifdef MOUSEKEY_ENABLE
    // Cursor
    #define MOUSEKEY_DELAY 50
    #define MOUSEKEY_INTERVAL 8
    #define MOUSEKEY_MOVE_DELTA 1
    #define MOUSEKEY_MAX_SPEED 14
    #define MOUSEKEY_TIME_TO_MAX 80
    // Scroll Wheel
    #define MOUSEKEY_WHEEL_DELAY 200
    #define MOUSEKEY_WHEEL_INTERVAL 60
    #define MOUSEKEY_WHEEL_DELTA 1
    #define MOUSEKEY_WHEEL_MAX_SPEED 2
    #define MOUSEKEY_WHEEL_TIME_TO_MAX 0
#endif

