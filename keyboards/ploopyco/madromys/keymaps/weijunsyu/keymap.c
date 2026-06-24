/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Define keycode aliases
#ifdef OOOOOOO
#error "Tried to override an existing definition for: 'OOOOOOO'!"
#endif
#define OOOOOOO     KC_NO
#define _SCROLL     DRAG_SCROLL
// Shortcuts
#define _G_UP       G(KC_UP)                // GUI + Up                         GENERAL shortcut to snap active window up
#define _G_DN       G(KC_DOWN)              // GUI + Down                       GENERAL shortcut to snap active window down
#define _G_LT       G(KC_LEFT)              // GUI + Left                       GENERAL shortcut to snap active window left
#define _G_RT       G(KC_RGHT)              // GUI + Right                      GENERAL shortcut to snap active window right
#define _LSG_LT     LSG(KC_LEFT)            // Shift + GUI + Left               GENERAL shortcut to move active window left one screen
#define _LSG_RT     LSG(KC_RGHT)            // Shift + GUI + Right              GENERAL shortcut to move active window right one screen
#define _LCG_UP     LCG(KC_UP)              // Ctrl + GUI + Up                  GENERAL shortcut to maximize active window


enum user_layer
{
    _L_MOUSE,       // Mouse layer
    _L_MO_SCROLL,   // Momentary scroll layer
    _L_SCROLL,      // Scroll layer
};

enum user_keycode
{
    _KC_TSC = SAFE_RANGE,   // Toggle scrolling
    _KC_LMS,                // Momentary scrolling, left
    _KC_RMS,                // Momentary scrolling, right
};


// Combo keys:
const uint16_t PROGMEM scroll_combo[] =     {_KC_LMS,   _KC_RMS,    COMBO_END};
const uint16_t PROGMEM middle_combo[] =     {KC_BTN1,   KC_BTN2,    COMBO_END};

const uint16_t PROGMEM back_combo[] =       {KC_BTN1,   _KC_LMS,    COMBO_END};
const uint16_t PROGMEM forward_combo[] =    {KC_BTN2,   _KC_RMS,    COMBO_END};

const uint16_t PROGMEM mv_left_combo[] =    {_G_LT,     _KC_LMS,    COMBO_END};
const uint16_t PROGMEM mv_right_combo[] =   {_G_RT,     _KC_RMS,    COMBO_END};
const uint16_t PROGMEM max_win_combo[] =    {_G_UP,     _G_DN,      COMBO_END};
combo_t key_combos[] = {
    COMBO(scroll_combo,     _KC_TSC),
    COMBO(middle_combo,     KC_BTN3),
    COMBO(back_combo,       KC_BTN4),
    COMBO(forward_combo,    KC_BTN5),
    COMBO(mv_left_combo,    _LSG_LT),
    COMBO(mv_right_combo,   _LSG_RT),
    COMBO(max_win_combo,    _LCG_UP),
};


// Global flags:
static bool g_scroll_mode;
static uint8_t g_base_layer;


// Private functions:
void _enter_scroll_mode(void) {
    if (!g_scroll_mode && !layer_state_is(_L_SCROLL)) {
        g_scroll_mode = true;
        layer_move(_L_SCROLL);
        g_base_layer = _L_SCROLL;
        toggle_drag_scroll();
    }
}

void _exit_scroll_mode(void) {
    if (g_scroll_mode && !layer_state_is(_L_MOUSE)) {
        g_scroll_mode = false;
        layer_move(_L_MOUSE);
        g_base_layer = _L_MOUSE;
        toggle_drag_scroll();
    }
}

void _toggle_scroll_mode(void) {
    if (g_scroll_mode) {
        _exit_scroll_mode();
    }
    else {
        _enter_scroll_mode();
    }
}

void _momentary_scroll_toggle(void) {
    if (g_scroll_mode) {
        g_scroll_mode = false;
        layer_move(_L_MOUSE);
    }
    else {
        g_scroll_mode = true;
        switch (g_base_layer) {
            case _L_MOUSE:
                layer_move(_L_MO_SCROLL);
                break;
            case _L_SCROLL:
                layer_move(_L_SCROLL);
                break;
            default:
                break;
        }
    }
    toggle_drag_scroll();
}


// Keymap:
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_L_MOUSE] = LAYOUT(
      //|-----------------------------------|
          KC_BTN1, KC_BTN2, KC_BTN1, KC_BTN2, 
      //|--------+--------+--------+--------|
          _KC_LMS,                   _KC_RMS 
      //|--------|                 |--------|
    ),
    [_L_MO_SCROLL] = LAYOUT(
      //|-----------------------------------|
          KC_BTN1, KC_BTN2, KC_BTN1, KC_BTN2, 
      //|--------+--------+--------+--------|
          _______,                   _______ 
      //|--------|                 |--------|
    ),
    [_L_SCROLL] = LAYOUT(
      //|-----------------------------------|
            _G_LT,   _G_DN,   _G_UP,   _G_RT, 
      //|--------+--------+--------+--------|
          _______,                   _______ 
      //|--------|                 |--------|
    )
};


// User functions:
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool lms_registered;
    static bool rms_registered;
    switch (keycode) {
        case _KC_TSC:
            if (record->event.pressed) {
                _toggle_scroll_mode();
            }
            return false;
        case _KC_LMS:
            if (record->event.pressed) {
                lms_registered = true;
                if (!rms_registered) {
                    _momentary_scroll_toggle();
                }
            }
            else {
                lms_registered = false;
                if (!rms_registered) {
                    _momentary_scroll_toggle();
                }
            }
            return false;
        case _KC_RMS:
            if (record->event.pressed) {
                rms_registered = true;
                if (!lms_registered) {
                    _momentary_scroll_toggle();
                }
            }
            else {
                rms_registered = false;
                if (!lms_registered) {
                    _momentary_scroll_toggle();
                }
            }
            return false;
        default: // Process all other keycodes normally
            return true;
    }
};


// Keyboard init (after firmware init finished):
void keyboard_post_init_user(void) {
    // Init startup values
    g_scroll_mode = false;
    g_base_layer = _L_MOUSE;

    _enter_scroll_mode(); // Default to scroll mode
}

