#include QMK_KEYBOARD_H
#include "features/casemodes.h"


enum layers {
    _BASE = 0,
    _SYM,
    _FUN,
    _NAV,
    _MOUSE,
};

#define FUN    MO(_FUN)

enum custom_keycodes {
    XCASE = SAFE_RANGE,
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
     XXXXXXX , KC_Q ,  KC_W   ,  KC_F  , KC_P   , KC_B   ,                                              KC_J,   KC_L ,  KC_U ,   KC_Y ,  KC_SCLN , XXXXXXX,
     KC_TAB  , KC_A ,  KC_R   ,  KC_S  , KC_T   , KC_G   ,                                              KC_M,   KC_N ,  KC_E ,   KC_I , KC_O, XXXXXXX,
     XXXXXXX , KC_Z ,  KC_X   ,  KC_C  , KC_D   , KC_V   , KC_LGUI, KC_LALT,           FUN ,  XCASE,    KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, XXXXXXX,
                                KC_F2  , XXXXXXX, KC_ALGR, KC_LSFT, CTL_T(KC_ESC),     LT(_SYM, KC_ENT), LT(_NAV, KC_SPC), LT(_MOUSE, KC_BSPC), KC_DEL, XXXXXXX
    ),
// double tap SYM to NAV, double tap FUN to MOUSE
// check out https://github.com/andrewjrae/kyria-keymap#features for "X-case"

// KC_INT1 for Euro sign
[_SYM] = LAYOUT(
     _______,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 , KC_5   ,                                            KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , _______,
     _______, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_COLN,                                         KC_DQUO, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, _______,
     _______, _______, KC_INT1, KC_EQL , KC_MINS, KC_SCLN, _______, _______,     _______, _______, KC_QUOT, KC_UNDS, KC_GRV ,  _______, KC_BSLS, _______,
                                _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

[_FUN] = LAYOUT(
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_F5,                                            KC_F6, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
      KC_WAKE, _______, _______, KC_PSCR,  KC_F5 , _______,                                        _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, KC_F12,
      KC_SLEP, _______, _______, _______, _______, _______, _______, _______,    _______, KC_RGUI, KC_RALT, _______, _______, _______, _______, _______,
                                 KC_PWR , _______, _______, _______, _______,    KC_RCTL, KC_RSFT, _______, _______, _______
    ),

[_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                        _______, _______, KC_PGDN, KC_PGUP, _______, _______,
      _______, _______, _______, _______, _______, _______,                                        KC_HOME, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END,
      _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

[_MOUSE] = LAYOUT(
      _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______,                                         _______, _______, KC_WH_D, KC_WH_U, _______, _______,
      KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, _______,                                         KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_R,
      _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
};

// enum combos {
//     FUN_SYM,
// };

// const uint16_t PROGMEM FUN_SYM_combo[] = {FUN, SYM, COMBO_END};

// combo_t key_combos[] = {
//     [FUN_SYM] = COMBO(FUN_SYM_combo, NAV),
// };

bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case XCASE:
            if (record->event.pressed) {
                enable_xcase();
            }
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}




















