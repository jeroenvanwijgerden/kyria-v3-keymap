#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYM,
    _FUN,
    _NAV,
    _MOUSE,
};

#define FUN    MO(_FUN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
     XXXXXXX , KC_Q ,  KC_W   ,  KC_E  , KC_R   , KC_T   ,                                              KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , XXXXXXX,
     KC_TAB  , KC_A ,  KC_S   ,  KC_D  , KC_F   , KC_G   ,                                              KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_ENT,
     XXXXXXX , KC_Z ,  KC_X   ,  KC_C  , KC_V   , KC_B   , KC_LGUI, KC_LALT,           FUN ,  KC_NO,    KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, XXXXXXX,
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
      _______, _______, _______, KC_PSCR,  KC_F5 , _______,                                        _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, KC_F12,
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