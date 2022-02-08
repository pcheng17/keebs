#pragma once

#include QMK_KEYBOARD_H

enum common_layers {
    _QWERTY,
    // _COLEMAK,
    _LOWER,
    _RAISE,
    _NAVI,
    _NUMPAD,
    _FUNC,
    _GAME,
    _ADJUST
};

enum common_custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    // KC_COLEMAK,
    KC_SLSL,
    KC_CLCL,
    KC_ARRW,
    KC_LEQ,
    KC_GEQ,
};

#define BASE     TO(_QWERTY)
#define GAME     TO(_GAME)
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define ADJUST   MO(_ADJUST)
#define NAVI     MO(_NAVI)
#define FUNC     MO(_FUNC)
#define NUMPAD   TG(_NUMPAD)

#define LWR_DEL  LT(_LOWER, KC_DEL)
#define NAV_SPC  LT(_NAVI, KC_SPC)
#define FNC_LFT  LT(_FUNC, KC_LEFT)

#define WINSNIP  S(G(KC_S))
#define WSLEFT   C(G(KC_LEFT))
#define WSRIGHT  C(G(KC_RIGHT))
#define CTLALTD  C(A(KC_DEL))
#define CTLESC   LCTL_T(KC_ESC)

#define W_HM_A   LGUI_T(KC_A)
#define W_HM_S   LALT_T(KC_S)
#define W_HM_D   LSFT_T(KC_D)
#define W_HM_F   LCTL_T(KC_F)

#define W_HM_J   LCTL_T(KC_J)
#define W_HM_K   RSFT_T(KC_K)
#define W_HM_L   LALT_T(KC_L)
#define W_HM_SC  RGUI_T(KC_SCLN)

#define M_HM_A   LCTL_T(KC_A)
#define M_HM_S   LALT_T(KC_S)
#define M_HM_D   LCMD_T(KC_D)
#define M_HM_F   LSFT_T(KC_F)

#define M_HM_J   LSFT_T(KC_J)
#define M_HM_K   LCMD_T(KC_K)
#define M_HM_L   LALT_T(KC_L)
#define M_HM_SC  LCTL_T(KC_SCLN)

// clang-format off
#define _________________QWERTY_L1_________________      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________      KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define _________________QWERTY_R3_________________      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _____________QWERTY_WIN_MOD_L2_____________      KC_A,    W_HM_S,  W_HM_D,  W_HM_F,  KC_G
#define _____________QWERTY_WIN_MOD_R2_____________      KC_H,    W_HM_J,  W_HM_K,  W_HM_L,  W_HM_SC

#define _____________QWERTY_MAC_MOD_L2_____________      M_HM_A,  M_HM_S,  M_HM_D,  M_HM_F,  KC_G
#define _____________QWERTY_MAC_MOD_R2_____________      KC_H,    M_HM_J,  M_HM_K,  M_HM_L,  M_HM_SC

#define _____________COLEMAK_MOD_DH_L1_____________      KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _____________COLEMAK_MOD_DH_L2_____________      KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _____________COLEMAK_MOD_DH_L3_____________      KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _____________COLEMAK_MOD_DH_R1_____________      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _____________COLEMAK_MOD_DH_R2_____________      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define _____________COLEMAK_MOD_DH_R3_____________      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH

#define __________________FUNC_L1__________________      KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX
#define __________________FUNC_L2__________________      KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX
#define __________________FUNC_L3__________________      KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX

#define ________________NUMPAD_R1__________________      XXXXXXX, KC_7,    KC_8,    KC_9,    KC_EQL
#define ________________NUMPAD_R2__________________      KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS
#define ________________NUMPAD_R3__________________      KC_ASTR, KC_1,    KC_2,    KC_3,    KC_PLUS
#define ________________NUMPAD_R4__________________      KC_SPC,  KC_0,    KC_COMM, KC_DOT,  XXXXXXX

#define __________HOME_ROW_MOD_WINDOWS_L___________      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define __________HOME_ROW_MOD_WINDOWS_R___________      XXXXXXX, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI

#define _________________LOWER_L1__________________      KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________LOWER_L2__________________      KC_HAEN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________LOWER_L3__________________      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _________________LOWER_R1__________________      KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________LOWER_R2__________________      XXXXXXX, KC_ARRW, KC_CLCL, KC_SLSL, XXXXXXX
#define _________________LOWER_R3__________________      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _________________RAISE_L1__________________      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L2__________________      KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_LEQ
#define _________________RAISE_L3__________________      XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_GEQ

#define _________________RAISE_R1__________________      KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS
#define _________________RAISE_R2__________________      XXXXXXX, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________      XXXXXXX, KC_LCBR, KC_RCBR, KC_SLSH, KC_QUES

#define         __________BLANK__________                _______, _______, _______
#define __________________BLANK____________________      _______, _______, _______, _______, _______
#define __________________NO_OP____________________      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
