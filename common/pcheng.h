#pragma once

#include QMK_KEYBOARD_H
#include "keyrows.h"

enum common_layers {
    _QWERTY,
    // _COLEMAK,
    _LOWER,
    _RAISE,
    _NAVI,
    _NUMPAD,
    _FNC,
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
#define LSPC     LT(_NAVI, KC_SPC)
#define NUMPAD   TG(_NUMPAD)
#define LOWER    LT(_LOWER, KC_DEL)
#define RAISE    MO(_RAISE)
#define ADJUST   MO(_ADJUST)

#define WINSNIP  S(G(KC_S))
#define WSLEFT   C(G(KC_LEFT))
#define WSRIGHT  C(G(KC_RIGHT))
#define CTLALTD  C(A(KC_DEL))
#define CTLESC   LCTL_T(KC_ESC)

#define MOD_A   LGUI_T(KC_A)
#define MOD_S   LALT_T(KC_S)
#define MOD_D   LSFT_T(KC_D)
#define MOD_F   LCTL_T(KC_F)

#define MOD_J   LCTL_T(KC_J)
#define MOD_K   RSFT_T(KC_K)
#define MOD_L   LALT_T(KC_L)
#define MOD_SC  RGUI_T(KC_SCLN)
