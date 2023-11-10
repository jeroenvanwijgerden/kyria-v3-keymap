/*
    Modified version of X-Case (https://github.com/andrewjrae/kyria-keymap#x-case)
    Removed the caps-word functionality because it doesn't mix with QMK's default Caps Word
    and it doesn't seem to work on its own (pressing the CAPSWRD key is equivalent to
    pressing a Gui key???).
*/

#pragma once

#include QMK_KEYBOARD_H

// enum for the xcase states
enum xcase_state {
    XCASE_OFF = 0,  // xcase is off
    XCASE_ON,       // xcase is actively on
    XCASE_WAIT,     // xcase is waiting for the delimiter input
};

// Get xcase state
enum xcase_state get_xcase_state(void);
// Enable xcase and pickup the next keystroke as the delimiter
void enable_xcase(void);
// Enable xcase with the specified delimiter
void enable_xcase_with(uint16_t delimiter);
// Disable xcase
void disable_xcase(void);

// Function to be put in process user
bool process_case_modes(uint16_t keycode, const keyrecord_t *record);