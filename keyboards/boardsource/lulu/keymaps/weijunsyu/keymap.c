#include QMK_KEYBOARD_H
#ifdef CONSOLE_ENABLE
    #include "print.h"
#endif

// List of keys / key combinations that are missing but could be useful:
// KC_SCRL                      Scroll Loc
//_ALTF4
//_LCABSC

// Define user constants

// Define user strings
#define _STR_3TB        "   "
#define _STR_3GV        "```"
#define _STR_SDV    "----------"                                                // short divider (10 chars)
#define _STR_LDV    "----------------------------------------------------------------------------------------------------" // 100 chars
#define _STR_SUD    "__________"
#define _STR_LUD    "____________________________________________________________________________________________________"
#define _STR_SED    "=========="
#define _STR_LED    "===================================================================================================="
#define _FLASHL     "qmk flash -kb boardsource/lulu/rp2040 -km weijunsyu -bl uf2-split-left"
#define _FLASHR     "qmk flash -kb boardsource/lulu/rp2040 -km weijunsyu -bl uf2-split-right"

// Define keycode aliases
#ifdef OOOOOOO
#error "Tried to override an existing definition for: 'OOOOOOO'!"
#endif
#define OOOOOOO     KC_NO
#define _UP         KC_UP
#define _DN         KC_DOWN
#define _RT         KC_RGHT
#define _LT         KC_LEFT
#define _EQUAL      KC_EQUAL
#define _INSERT     KC_INSERT
// Shift keycode aliases
#define _S_SCLN     S(KC_SCLN)
#define _S_QUOT     S(KC_QUOT)
#define _S_COMM     S(KC_COMM)
#define _S_DOT      S(KC_DOT)
#define _S_SLSH     S(KC_SLSH)
#define _S_ENT      S(KC_ENT)
#define _S_TAB      S(KC_TAB)
#define _S_SPC      S(KC_SPC)
#define _S_BSPC     S(KC_BSPC)
#define _S_DEL      S(KC_DEL)
// Ctrl keycode aliases
#define _C_BSLS     C(KC_BSLS)
#define _C_SCLN     C(KC_SCLN)
#define _C_QUOT     C(KC_QUOT)
#define _C_COMM     C(KC_COMM)
#define _C_DOT      C(KC_DOT)
#define _C_SLSH     C(KC_SLSH)
#define _C_ENT      C(KC_ENT)
#define _C_HOME     C(KC_HOME)
#define _C_END      C(KC_END)
// GUI keycode aliases
#define _G_PSCR     G(KC_PSCR)
#define _C_BSC      C(KC_BSPC)
// Modifier aliases
#define _ALTESC     LALT_T(KC_ESC)          // Hold: KC_LALT;   Tap: KC_ESC
#define _SFTMIN     LSFT_T(KC_MINS)         // Hold: KC_LSFT;   Tap: KC_MINS    Ctrl: OS_LSFT
// Layer management aliases
// Hold, tap
#define _FKLSPC     LT(_L_FKL, KC_SPC)      // Hold: _L_FKL;    Tap: KC_SPC
#define _NAVBSC     LT(_L_NAV, KC_BSPC)     // Hold: _L_NAV;    Tap: KC_BSPC
#define _NSMTAB     LT(_L_NSM, KC_TAB)      // Hold: _L_NSM;    Tap: KC_TAB
// One-shot
#define _OSLSFT     OSL(_L_SFT)             // One-shot layer: _L_SFT           Ctrl: KC_CAPS
#define _OSLNSM     OSL(_L_NSM)             // One-shot layer: _L_NSM
#define _OSLINV     OSL(_T_INV)             // One-shot layer: _T_INV
// Toggle
#define _TGLNUM     TG(_L_NUM)              // Toggle layer: _L_NUM
// Shortcuts
#define _CTLPLS     C(KC_EQUAL)             // Ctrl + Equals                    GENERAL shortcut to increase size
#define _CTLMIN     C(KC_MINS)              // Ctrl + Minus                     GENERAL shortcut to decrease size
#define _CTLDFT     C(KC_0)                 // Ctrl + 0                         GENERAL shortcut to reset to default size
#define _CTLLFT     C(KC_LEFT)              // Ctrl + Left                      GENERAL shortcut to move left by one word
#define _CTLRGT     C(KC_RIGHT)             // Ctrl + Right                     GENERAL shortcut to move right by one word
#define _CTLHOM     C(KC_HOME)              // Ctrl + Home                      GENERAL shortcut to jump to the start of page
#define _CTLEND     C(KC_END)               // Ctrl + End                       GENERAL shortcut to jump to the end of page
#define _CTRBRK     C(KC_BRK)               // Ctrl + Break                     WINDOWS shortcut to halt execution in cmd; stop compile in Visual Studio
#define _LCADEL     LCA(KC_DEL)             // Ctrl + Alt + Delete              WINDOWS shortcut to bring up diag menu that interrupts
#define _LCSESC     LCS(KC_ESC)             // Ctrl + Shift + Esc               WINDOWS shortcut to bring up task manager
#define _ALTF4      A(KC_F4)                // Alt + F4                         GENERAL shortcut to close active window
#define _LCABSC     LCA(KC_BSPC)            // Ctrl+ Alt + Backspace            GNU/LINUX shortcut to force close the X server (restart GUI)
#define _LCAT       LCA(KC_T)               // Ctrl + Alt + T                   LINUX (mint/cinnamon) shortcut to bring up the terminal
#define _G_UP       G(KC_UP)                // GUI + Up                         GENERAL shortcut to snap active window up
#define _G_DN       G(KC_DOWN)              // GUI + Down                       GENERAL shortcut to snap active window down
#define _G_LT       G(KC_LEFT)              // GUI + Left                       GENERAL shortcut to snap active window left
#define _G_RT       G(KC_RGHT)              // GUI + Right                      GENERAL shortcut to snap active window right
#define _LSG_LT     LSG(KC_LEFT)            // Shift + GUI + Left               GENERAL shortcut to move active window left one screen
#define _LSG_RT     LSG(KC_RGHT)            // Shift + GUI + Right              GENERAL shortcut to move active window right one screen
#define _WINBRK     G(KC_BRK)               // GUI + Break                      WINDOWS shortcut to bring up the System Information Panel


enum user_layer
{
    _L_BASE,      // Base layer (QWERTY)
    _L_SFT,       // Shift layer
    _L_NSM,       // Numbers and symbols layer
    _L_NUM,       // Left hand numpad layer
    _L_NAV,       // Navigation layer
    _L_FKL,       // F-keys and shortcuts layer
    _T_CAP,       // Temp layer for Caps Word feature
};

enum user_keycode {
    _TOBASE = SAFE_RANGE,   // Force return to base layer
    _KC_CTL,                // Global tracked unique alias for KC_LCTL
    _KC_UND,                // KC_UNDS that sends KC_MINS when shifted
    _KC_ENT,                // KC_ENT that swaps the shift and ctrl modifiers /// Unused
    _KC_FKL,                // Last used F-key, default F12
    _SFTCOS,                // Shift that sends oneshot when ctrl mods active
    _P0_BSC,                // KC_P0 that sends KC_BSPC when shifted
    _PENT_S,                // KC_PENT that sends KC_SPC when shifted
    _PSLS_Q,                // KC_PSLS that sends KC_Q when ctrl mods active
    _KC_P7W,                // KC_P7 that sends KC_W when ctrl mods active
    _KC_P8E,                // KC_P8 that sends KC_E when ctrl mods active
    _KC_P9R,                // KC_P9 that sends KC_R when ctrl mods active
    _PMNS_T,                // KC_PMMS that sends KC_T when ctrl mods active
    _PAST_A,                // KC_PAST that sends KC_A when ctrl mods active
    _KC_P4S,                // KC_P4 that sends KC_S when ctrl mods active
    _KC_P5D,                // KC_P5 that sends KC_D when ctrl mods active
    _KC_P6F,                // KC_P6 that sends KC_F when ctrl mods active
    _PPLS_G,                // KC_PPLS that sends KC_G when ctrl mods active
    _PDOT_Z,                // KC_PDOT that sends KC_Z when ctrl mods active
    _KC_P1X,                // KC_P1 that sends KC_X when ctrl mods active
    _KC_P2C,                // KC_P2 that sends KC_C when ctrl mods active
    _KC_P3V,                // KC_P3 that sends KC_V when ctrl mods active
    _EQAL_B,                // KC_EQAL that sends KC_B when ctrl mods active
    _KC_3TB,                // "   " 3 space tab
    _KC_3GV,                // "```"
    _KC_SDV,                // "----------"
    _KC_LDV,                // "----------------------------------------------------------------------------------------------------"
    _KC_SUD,                // "__________"
    _KC_LUD,                // "____________________________________________________________________________________________________"
    _KC_SED,                // "=========="
    _KC_LED,                // "===================================================================================================="
    _KC_SEN,                // S(KC_ENT) that send C(KC_TAB) when ctrl active
    _OS_SFT,                // Force oneshot mod; no held action
    _OS_CTL,                // Force oneshot mod; no held action
    _OS_ALT,                // Force oneshot mod; no held action
    _OS_GUI,                // Force oneshot mod; no held action
    _KC_FHL,                // Send flash cmd string (_FLASHL) for left side
    _KC_FHR,                // Send flash cmd string (_FLASHL) for right side
    _KC_RST,                // Send the reboot command (QK_REBOOT) manually `soft_reset_keyboard()`
    _KC_BOT,                // Send the bootloader command (QK_BOOTLOADER) manually `reset_keyboard()`
};


// Combos:
#include "g/keymap_combo.h"


// Global flags:
static uint8_t g_mod_state;
static uint8_t g_weak_mod_state;
static uint8_t g_oneshot_mod_state;
static uint8_t g_last_used_fkey;
static bool g_user_ctrl_registered;


// Private functions:
void init_global_flags(void) {
    g_last_used_fkey = KC_F12;
    g_user_ctrl_registered = false;
}

void clear_custom_flags(void) {
    g_user_ctrl_registered = false;
}


// Keymap:
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_L_BASE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _TOBASE, _TGLNUM, _OS_SFT, _OS_CTL, _OS_ALT, _OS_GUI,                      KC_CAPS,  KC_NUM, KC_PSCR, KC_PAUS, KC_VOLD, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _ALTESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      _SFTMIN,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _KC_FKL,    _INSERT,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _KC_UND,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  KC_DEL, _KC_CTL, _NSMTAB, _FKLSPC,    _NAVBSC, _OSLSFT,  KC_ENT, _KC_SEN
                             //`-----------------------------------'  `-----------------------------------'
  ),

[_L_SFT] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _TOBASE, XXXXXXX, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_EXLM, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),                      S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MINS, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),                      S(KC_H), S(KC_J), S(KC_K), S(KC_L), _S_SCLN, _S_QUOT,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      KC_PLUS, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), XXXXXXX,    XXXXXXX, S(KC_N), S(KC_M), _S_COMM,  _S_DOT, _S_SLSH,  _EQUAL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 _KC_SDV, _KC_3GV, _KC_3TB,  KC_SPC,    KC_BSPC, OOOOOOO, OOOOOOO, KC_TILD
                             //`-----------------------------------'  `-----------------------------------'
  ),

[_L_NSM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _TOBASE, XXXXXXX, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LABK, KC_EXLM, KC_AMPR, KC_PIPE, KC_LBRC, KC_RBRC,                      KC_MINS,    KC_7,    KC_8,    KC_9,    KC_0, KC_RABK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RABK,   KC_AT, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,                      KC_PLUS,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      KC_SLSH, KC_ASTR, KC_CIRC, KC_PERC, KC_LCBR, KC_RCBR, QK_LLCK,     KC_DEL,  _EQUAL,    KC_1,    KC_2,    KC_3,  KC_DOT,  KC_SPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_BSPC,  KC_ENT, OOOOOOO,  KC_SPC,    KC_BSPC,    KC_0,  KC_ENT,  KC_TAB
                             //`-----------------------------------'  `-----------------------------------'
  ),

[_L_NUM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _TOBASE, _TGLNUM, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, _PSLS_Q, _KC_P7W, _KC_P8E, _KC_P9R, _PMNS_T,                      MS_WHLU, _CTLLFT,   KC_UP, _CTLRGT, KC_PGUP, _CTLHOM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _ALTESC, _PAST_A, _KC_P4S, _KC_P5D, _KC_P6F, _PPLS_G,                      MS_WHLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _CTLEND,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      _SFTCOS, _PDOT_Z, _KC_P1X, _KC_P2C, _KC_P3V, _EQAL_B, _INSERT,    XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  KC_DEL, _KC_CTL, _P0_BSC, _PENT_S,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                             //`-----------------------------------'  `-----------------------------------'
  ),

[_L_NAV] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _TOBASE, XXXXXXX, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, MS_BTN5, MS_WHLL,   MS_UP, MS_WHLR, MS_WHLU,                      MS_WHLU, _CTLLFT,   KC_UP, _CTLRGT, KC_PGUP, _CTLHOM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, MS_BTN4, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                      MS_WHLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _CTLEND,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    QK_LLCK, MS_BTN1, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, MS_BTN2,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  KC_DEL, MS_BTN3, MS_BTN2, MS_BTN1,    OOOOOOO,  KC_ESC,  KC_ENT, XXXXXXX
                             //`-----------------------------------'  `-----------------------------------'
  ),

[_L_FKL] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _TOBASE, XXXXXXX, _______, _______, _______, _______,                      _KC_FHL, _KC_FHR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _G_PSCR,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _CTLPLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _LCAT,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _CTLMIN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      _LCSESC,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _CTRBRK, QK_LLCK,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX, OOOOOOO,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                             //`-----------------------------------'  `-----------------------------------'
  ),

[_T_CAP] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______, _______,    _______, _______, _______, _______
                             //`-----------------------------------'  `-----------------------------------'
  )
};

/*[_BLANK] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                             //`-----------------------------------'  `-----------------------------------'
  )*/


// User functions:
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _ALTESC:
            return 0; // Do hold action on double-tap hold.
        case _NAVBSC:
            return 0;
        default:
            return QUICK_TAP_TERM; // Do tap action hold on double-tap hold if within QUICK_TAP_TERM timeframe.
    }
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _FKLSPC:
            return false; // Do not immediately select the hold action when another key is pressed.
        case _NAVBSC:
            return false;
        case _SFTMIN:
            return false;
        default:
            return true; // Immediately select the hold action when another key is pressed.
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    g_mod_state = get_mods(); // Snapshot of the current modifier state
    g_weak_mod_state = get_weak_mods(); // Snapshot of the current weak modifier state
    g_oneshot_mod_state = get_oneshot_mods(); // Snapshot of the current oneshot modifier state
    switch (keycode) {
        case _TOBASE:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS); // If caps lock is currently on, toggle it off
                }
                if (!host_keyboard_led_state().num_lock) {
                    tap_code(KC_NUM); // If num lock is currently off, toggle it on
                }
                if (host_keyboard_led_state().scroll_lock) {
                    tap_code(KC_SCRL); // If scroll lock is currently on, toggle it off
                }
                #ifdef CAPS_WORD_ENABLE
                    if (is_caps_word_on()) {
                        caps_word_off();
                    }
                #endif
                clear_mods(); // Clear any active modifiers
                clear_weak_mods(); // Clears any active weak modifiers
                clear_oneshot_mods(); // Clear any active oneshot modifiers
                clear_oneshot_locked_mods(); // Clear any active oneshot locked modifiers
                clear_custom_flags(); // Clear any active custom modifiers
                clear_keyboard();
                layer_clear(); // Clear all layers
            }
            return false; // Stop further processing of keycode
        case _SFTMIN:
            static bool _sftmin_shift_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    register_mods(MOD_MASK_SHIFT);
                    add_oneshot_mods(MOD_MASK_SHIFT);
                    _sftmin_shift_registered = true;
                    return false;
                }
            }
            else {
                if (_sftmin_shift_registered) {
                    unregister_mods(MOD_MASK_SHIFT);
                    _sftmin_shift_registered = false;
                    return false;
                }
            }
            return true; // Continue to resolve as normal
        case _KC_CTL:
            if (record->event.pressed) {
                register_mods(MOD_MASK_CTRL);
                g_user_ctrl_registered = true;
            }
            else {
                if (g_user_ctrl_registered) {
                    unregister_mods(MOD_MASK_CTRL);
                    g_user_ctrl_registered = false;
                }
            }
            return false;
        case _KC_UND:
            static bool _kc_und_mins_registered; // Track KC_MINS status
            static bool _kc_und_tild_registered; // Track KC_TILD status
            if (record->event.pressed) {
                if (!_kc_und_tild_registered && (g_mod_state & MOD_MASK_CTRL || g_oneshot_mod_state & MOD_MASK_CTRL)) {
                    del_mods(MOD_MASK_CTRL); // Cancel ctrl status temporarily
                    del_oneshot_mods(MOD_MASK_CTRL);
                    //register_code16(KC_TILD);
                    _kc_und_tild_registered = true;
                }
                else if (!_kc_und_mins_registered && g_mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT); // Cancel shift status temporarily
                    register_code(KC_MINS);
                    _kc_und_mins_registered = true;
                }
                else {
                    register_code16(KC_UNDS);
                }
                set_mods(g_mod_state); // Reset the mod state
                set_oneshot_mods(g_oneshot_mod_state);
            }
            else {
                // If KC_MINS still being registered after release; unregister:
                if (_kc_und_mins_registered) {
                    unregister_code(KC_MINS);
                    _kc_und_mins_registered = false;
                    return false;
                }
                // If KC_TILD still being registered after release; unregister:
                if (_kc_und_tild_registered) {
                    //unregister_code16(KC_TILD);
                    _kc_und_tild_registered = false;
                    return false;
                }
                unregister_code16(KC_UNDS);
            }
            return false;
        case _NSMTAB:
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    return false; // Do nothing if ctrl is held
                }
            }
            return true;
        case _OSLSFT:
            if (record->event.pressed) {
                #ifdef CAPS_WORD_ENABLE
                    if (g_user_ctrl_registered) {
                        caps_word_on();
                        return false;
                    }
                    if (is_caps_word_on()) {
                        caps_word_off();
                        return false;
                    }
                #endif
            }
            return true;
        case _KC_SEN:
            static bool _kc_cap_tab_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    register_code(KC_TAB); // If ctrl is active, send tab (do ctrl + tab action)
                    _kc_cap_tab_registered = true;
                    return false;
                }
                tap_code16(S(KC_ENT));
            }
            else {
                if (_kc_cap_tab_registered) {
                    unregister_code(KC_TAB);
                    _kc_cap_tab_registered = false;
                    return false;
                }
            }
            return false;
        case _KC_ENT:
            if (record->event.pressed) {
                if (g_mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    add_mods(MOD_MASK_SHIFT);
                }
                else if (g_mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    add_mods(MOD_MASK_CTRL);
                }
                register_code(KC_ENT);
                set_mods(g_mod_state);
            }
            else {
                unregister_code(KC_ENT);
            }
            return false;
        case KC_F1:
            g_last_used_fkey = KC_F1;
            return true;
        case KC_F2:
            g_last_used_fkey = KC_F2;
            return true;
        case KC_F3:
            g_last_used_fkey = KC_F3;
            return true;
        case KC_F4:
            g_last_used_fkey = KC_F4;
            return true;
        case KC_F5:
            g_last_used_fkey = KC_F5;
            return true;
        case KC_F6:
            g_last_used_fkey = KC_F6;
            return true;
        case KC_F7:
            g_last_used_fkey = KC_F7;
            return true;
        case KC_F8:
            g_last_used_fkey = KC_F8;
            return true;
        case KC_F9:
            g_last_used_fkey = KC_F9;
            return true;
        case KC_F10:
            g_last_used_fkey = KC_F10;
            return true;
        case KC_F11:
            g_last_used_fkey = KC_F11;
            return true;
        case KC_F12:
            g_last_used_fkey = KC_F12;
            return true;
        case _KC_FKL:
            if (record->event.pressed) {
                register_code(g_last_used_fkey);
            }
            else {
                unregister_code(g_last_used_fkey);
            }
            return false;
        case _KC_3TB:
            if (record->event.pressed) {
                SEND_STRING(_STR_3TB);
            }
            return false;
        case _KC_3GV:
            if (record->event.pressed) {
                SEND_STRING(_STR_3GV);
            }
            return false;
        case _KC_SDV:
            if (record->event.pressed) {
                SEND_STRING(_STR_SDV);
            }
            return false;
        case _KC_LDV:
            if (record->event.pressed) {
                SEND_STRING(_STR_LDV);
            }
            return false;
        case _KC_SUD:
            if (record->event.pressed) {
                SEND_STRING(_STR_SUD);
            }
            return false;
        case _KC_LUD:
            if (record->event.pressed) {
                SEND_STRING(_STR_LUD);
            }
            return false;
        case _KC_SED:
            if (record->event.pressed) {
                SEND_STRING(_STR_SED);
            }
            return false;
        case _KC_LED:
            if (record->event.pressed) {
                SEND_STRING(_STR_LED);
            }
            return false;
        case _PSLS_Q:
            static bool _psls_q_psls_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_Q);
                    return false;
                }
                register_code(KC_PSLS);
                _psls_q_psls_registered = true;
            }
            else {
                if (_psls_q_psls_registered) {
                    unregister_code(KC_PSLS);
                    _psls_q_psls_registered = false;
                }
            }
            return false;
        case _KC_P7W:
            static bool _kc_p7w_p7_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_W);
                    return false;
                }
                register_code(KC_P7);
                _kc_p7w_p7_registered = true;
            }
            else {
                if (_kc_p7w_p7_registered) {
                    unregister_code(KC_P7);
                    _kc_p7w_p7_registered = false;
                }
            }
            return false;
        case _KC_P8E:
            static bool _kc_p8e_p8_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_E);
                    return false;
                }
                register_code(KC_P8);
                _kc_p8e_p8_registered = true;
            }
            else {
                if (_kc_p8e_p8_registered) {
                    unregister_code(KC_P8);
                    _kc_p8e_p8_registered = false;
                }
            }
            return false;
        case _KC_P9R:
            static bool _kc_p9r_p9_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_R);
                    return false;
                }
                register_code(KC_P9);
                _kc_p9r_p9_registered = true;
            }
            else {
                if (_kc_p9r_p9_registered) {
                    unregister_code(KC_P9);
                    _kc_p9r_p9_registered = false;
                }
            }
            return false;
        case _PMNS_T:
            static bool _pmns_t_pmns_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_T);
                    return false;
                }
                register_code(KC_PMNS);
                _pmns_t_pmns_registered = true;
            }
            else {
                if (_pmns_t_pmns_registered) {
                    unregister_code(KC_PMNS);
                    _pmns_t_pmns_registered = false;
                }
            }
            return false;
        case _PAST_A:
            static bool _past_a_past_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_A);
                    return false;
                }
                register_code(KC_PAST);
                _past_a_past_registered = true;
            }
            else {
                if (_past_a_past_registered) {
                    unregister_code(KC_PAST);
                    _past_a_past_registered = false;
                }
            }
            return false;
        case _KC_P4S:
            static bool _kc_p4s_p4_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_S);
                    return false;
                }
                register_code(KC_P4);
                _kc_p4s_p4_registered = true;
            }
            else {
                if (_kc_p4s_p4_registered) {
                    unregister_code(KC_P4);
                    _kc_p4s_p4_registered = false;
                }
            }
            return false;
        case _KC_P5D:
            static bool _kc_p5d_p5_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_D);
                    return false;
                }
                register_code(KC_P5);
                _kc_p5d_p5_registered = true;
            }
            else {
                if (_kc_p5d_p5_registered) {
                    unregister_code(KC_P5);
                    _kc_p5d_p5_registered = false;
                }
            }
            return false;
        case _KC_P6F:
            static bool _kc_p6f_p6_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_F);
                    return false;
                }
                register_code(KC_P6);
                _kc_p6f_p6_registered = true;
            }
            else {
                if (_kc_p6f_p6_registered) {
                    unregister_code(KC_P6);
                    _kc_p6f_p6_registered = false;
                }
            }
            return false;
        case _PPLS_G:
            static bool _ppls_g_ppls_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_G);
                    return false;
                }
                register_code(KC_PPLS);
                _ppls_g_ppls_registered = true;
            }
            else {
                if (_ppls_g_ppls_registered) {
                    unregister_code(KC_PPLS);
                    _ppls_g_ppls_registered = false;
                }
            }
            return false;
        case _PDOT_Z:
            static bool _pdot_z_pdot_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_Z);
                    return false;
                }
                register_code(KC_PDOT);
                _pdot_z_pdot_registered = true;
            }
            else {
                if (_pdot_z_pdot_registered) {
                    unregister_code(KC_PDOT);
                    _pdot_z_pdot_registered = false;
                }
            }
            return false;
        case _KC_P1X:
            static bool _kc_p1x_p1_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_X);
                    return false;
                }
                register_code(KC_P1);
                _kc_p1x_p1_registered = true;
            }
            else {
                if (_kc_p1x_p1_registered) {
                    unregister_code(KC_P1);
                    _kc_p1x_p1_registered = false;
                }
            }
            return false;
        case _KC_P2C:
            static bool _kc_p2c_p2_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_C);
                    return false;
                }
                register_code(KC_P2);
                _kc_p2c_p2_registered = true;
            }
            else {
                if (_kc_p2c_p2_registered) {
                    unregister_code(KC_P2);
                    _kc_p2c_p2_registered = false;
                }
            }
            return false;
        case _KC_P3V:
            static bool _kc_p3v_p3_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_V);
                    return false;
                }
                register_code(KC_P3);
                _kc_p3v_p3_registered = true;
            }
            else {
                if (_kc_p3v_p3_registered) {
                    unregister_code(KC_P3);
                    _kc_p3v_p3_registered = false;
                }
            }
            return false;
        case _EQAL_B:
            static bool _eqal_b_equal_registered;
            if (record->event.pressed) {
                if (g_user_ctrl_registered) {
                    tap_code(KC_B);
                    return false;
                }
                register_code16(KC_EQUAL);
                _eqal_b_equal_registered = true;
            }
            else {
                if (_eqal_b_equal_registered) {
                    unregister_code16(KC_EQUAL);
                    _eqal_b_equal_registered = false;
                }
            }
            return false;
        case _SFTCOS:
            if (record->event.pressed) {
                register_mods(MOD_MASK_SHIFT);
                if (g_user_ctrl_registered) {
                    add_oneshot_mods(MOD_MASK_SHIFT);
                }
            }
            else {
                unregister_mods(MOD_MASK_SHIFT);
            }
            return false;
        case _P0_BSC:
            static bool _p0_bsc_bspc_registered;
            if (record->event.pressed) {
                if (g_mod_state & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_BSPC);
                    set_mods(g_mod_state);
                    _p0_bsc_bspc_registered = true;
                    return false;
                }
                register_code(KC_P0);
            }
            else {
                if (_p0_bsc_bspc_registered) {
                    unregister_code(KC_BSPC);
                    _p0_bsc_bspc_registered = false;
                    return false;
                }
                unregister_code(KC_P0);
            }
            return false;
        case _PENT_S:
            static bool _pent_s_spc_registered;
            if (record->event.pressed) {
                if (g_mod_state & MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_SPC);
                    set_mods(g_mod_state);
                    _pent_s_spc_registered = true;
                    return false;
                }
                register_code(KC_PENT);
            }
            else {
                if (_pent_s_spc_registered) {
                    unregister_code(KC_SPC);
                    _pent_s_spc_registered = false;
                    return false;
                }
                unregister_code(KC_PENT);
            }
            return false;
        case _OS_SFT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_MASK_SHIFT);
            }
            return false;
        case _OS_CTL:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_MASK_CTRL);
            }
            return false;
        case _OS_ALT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_MASK_ALT);
            }
            return false;
        case _OS_GUI:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_MASK_GUI);
            }
            return false;
        case _KC_FHL:
            if (record->event.pressed) {
                SEND_STRING(_FLASHL);
            }
            return false;
        case _KC_FHR:
            if (record->event.pressed) {
                SEND_STRING(_FLASHR);
            }
            return false;
        case _KC_RST:
            if (record->event.pressed) {
                soft_reset_keyboard(); // Reboots the keyboard
            }
            return false;
        case _KC_BOT:
            if (record->event.pressed) {
                reset_keyboard(); // Send keyboard into bootloader
            }
            return false;
        default: // Process all other keycodes normally
            return true;
    }
};

//void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        default:
//            break;
//    }
//};

#ifdef CAPS_WORD_ENABLE
    bool caps_word_press_user(uint16_t keycode) {
        // Gets called on each keypress if Caps Word is on, BEFORE processing the key
        switch (keycode) {
            // Keycodes that continue Caps Word, with shift applied
            case KC_A ... KC_Z:
                add_weak_mods(MOD_BIT(KC_LSFT));
                return true;
            // Keycodes that continue Caps Word, without shifting
            case KC_CAPS: // Skip processing of the caps lock key
            case KC_1 ... KC_0:
            case KC_BSPC:
            case KC_DEL:
            case KC_UNDS:
            case KC_BSLS:
            case KC_SLSH:
            case KC_PIPE:
            case KC_MINS:
            case KC_DOT:
                return true;
            default:
                return false;  // Deactivate Caps Word
        }
    };

    void caps_word_set_user(bool active) {
        if (active) {
            layer_on(_T_CAP);
        }
        else {
            layer_off(_T_CAP);
        }
    };
#endif

/* RGB LED LAYOUT:
TOP-SIDE OF BOARD: (LED#)
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           11,      10,       9,       8,       7,       6,                           41,      42,      43,      44,      45,      46,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           12,      13,      14,     15,       16,      17,                           52,      51,      50,      49,      48,      47,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           23,      22,      21,      20,      19,      18,                           53,      54,      55,      56,      57,      58,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------|--------+--------+--------+--------+--------+--------|
           24,      25,      26,      27,      28,      29,      30,         65,      64,      63,      62,      61,      60,      59,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      34,       33,      32,     31,         66,      67,      68,      69
                             //`-----------------------------------'  `-----------------------------------'
*/


// Keyboard init (after firmware init finished):
void keyboard_post_init_user(void) {
    #ifdef CONSOLE_ENABLE
        debug_enable=true;
        //debug_matrix=true;
        //debug_keyboard=true;
        //debug_mouse=true;
    #endif
    // Turn off all LEDS on startup:
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);

    init_global_flags();
}


// State management and update cycle functions:
layer_state_t layer_state_set_user(layer_state_t state) {
    // This gets called only once, on initial entering of the layer
    switch (get_highest_layer(state)) {
        case _L_NUM:
            if (!host_keyboard_led_state().num_lock) {
                tap_code(KC_NUM); // If in the numpad layer, ensure num_lock defaults to on
            }
            break;
        default:
            // Otherwise, process as normal
            break;
    }
  return state;
}

// No need to 'reset' LEDs off here
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Set the default state: (Keyboard ON indicator)
    RGB_MATRIX_INDICATOR_SET_COLOR(11, 35, 0, 0); // RGB_MATRIX_INDICATOR_SET_COLOR(LED#, R, G, B)

    if ((get_oneshot_mods() & MOD_MASK_SHIFT) && (get_mods() & MOD_MASK_SHIFT)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(9, 100, 100, 0);
    }
    if ((get_oneshot_mods() & MOD_MASK_SHIFT) && !(get_mods() & MOD_MASK_SHIFT)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(9, 100, 0, 0);
    }
    if (!(get_oneshot_mods() & MOD_MASK_SHIFT) && (get_mods() & MOD_MASK_SHIFT)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(9, 0, 100, 0);
    }

    if ((get_oneshot_mods() & MOD_MASK_CTRL) && (get_mods() & MOD_MASK_CTRL)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(8, 100, 100, 0);
    }
    if ((get_oneshot_mods() & MOD_MASK_CTRL) && !(get_mods() & MOD_MASK_CTRL)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(8, 100, 0, 0);
    }
    if (!(get_oneshot_mods() & MOD_MASK_CTRL) && (get_mods() & MOD_MASK_CTRL)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(8, 0, 100, 0);
    }

    if ((get_oneshot_mods() & MOD_MASK_ALT) && (get_mods() & MOD_MASK_ALT)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(7, 100, 100, 0);
    }
    if ((get_oneshot_mods() & MOD_MASK_ALT) && !(get_mods() & MOD_MASK_ALT)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(7, 100, 0, 0);
    }
    if (!(get_oneshot_mods() & MOD_MASK_ALT) && (get_mods() & MOD_MASK_ALT)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(7, 0, 100, 0);
    }

    if ((get_oneshot_mods() & MOD_MASK_GUI) && (get_mods() & MOD_MASK_GUI)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(6, 100, 100, 0);
    }
    if ((get_oneshot_mods() & MOD_MASK_GUI) && !(get_mods() & MOD_MASK_GUI)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(6, 100, 0, 0);
    }
    if (!(get_oneshot_mods() & MOD_MASK_GUI) && (get_mods() & MOD_MASK_GUI)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(6, 0, 100, 0);
    }

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _L_SFT:
            RGB_MATRIX_INDICATOR_SET_COLOR(30, 100, 100, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(65, 100, 100, 0);
            break;
        case _L_NSM:
            RGB_MATRIX_INDICATOR_SET_COLOR(30, 0, 100, 0);
            break;
        case _L_NUM:
            RGB_MATRIX_INDICATOR_SET_COLOR(30, 100, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(65, 100, 0, 0);
            break;
        case _L_NAV:
            RGB_MATRIX_INDICATOR_SET_COLOR(65, 0, 100, 0);
            break;
        case _L_FKL:
            RGB_MATRIX_INDICATOR_SET_COLOR(30, 0, 100, 0);
            break;
        default:
            RGB_MATRIX_INDICATOR_SET_COLOR(30, 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(65, 0, 0, 0);
            break;
    }

    if ((host_keyboard_led_state().caps_lock) && (get_highest_layer(layer_state|default_layer_state) == _T_CAP)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(41, 100, 100, 0);
    }
    if ((host_keyboard_led_state().caps_lock) && !(get_highest_layer(layer_state|default_layer_state) == _T_CAP)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(41, 100, 0, 0);
    }
    if (!(host_keyboard_led_state().caps_lock) && (get_highest_layer(layer_state|default_layer_state) == _T_CAP)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(41, 0, 100, 0);
    }

    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(42, 35, 0, 0);
    }
    return false;
}






































