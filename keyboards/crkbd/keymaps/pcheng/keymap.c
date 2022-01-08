/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _NAVI,
    _NUMPAD,
    _FNC,
    _COLEMAK,
    _ADJUST
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    CPPCOMM,
    COLCOL,
    ARROW,
    LEQ,
    GEQ,
};

#define BASE     TO(_QWERTY)
#define LOWER    LT(_LOWER, KC_DEL)
#define RAISE    MO(_RAISE)
#define LSPACE   LT(_NAVI, KC_SPC)
#define FNC      MO(_FNC)
#define ADJUST   MO(_ADJUST)

#define CTLESC   LCTL_T(KC_ESC)
#define WINSNIP  S(G(KC_S))
#define WSLEFT   C(G(KC_LEFT))
#define WSRIGHT  C(G(KC_RIGHT))
#define CTLALTD  C(A(KC_DEL))

#define MOD_A   LGUI_T(KC_A)
#define MOD_S   LALT_T(KC_S)
#define MOD_D   LSFT_T(KC_D)
#define MOD_F   LCTL_T(KC_F)

#define MOD_J   LCTL_T(KC_J)
#define MOD_K   RSFT_T(KC_K)
#define MOD_L   LALT_T(KC_L)
#define MOD_SC  RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_QWERTY] = LAYOUT_split_3x6_3(
    //.-----------------------------------------------------.                    .-----------------------------------------------------.
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         CTLESC,    KC_A,   MOD_S,   MOD_D,   MOD_F,    KC_G,                         KC_H,   MOD_J,   MOD_K,   MOD_L,  MOD_SC, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,   LOWER,  LSPACE,     KC_SPC,   RAISE,     FNC
                                        //'--------------------------'  '--------------------------'

    ),

    [_LOWER] = LAYOUT_split_3x6_3(
    //.-----------------------------------------------------.                    .-----------------------------------------------------.
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_HAEN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   ARROW, CPPCOMM, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  COLCOL, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //'--------------------------'  '--------------------------'
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
    //.-----------------------------------------------------.                    .-----------------------------------------------------.
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_UNDS, KC_MINS, KC_PLUS,  KC_EQL,     LEQ,                      XXXXXXX, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,  KC_GRV,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX,   KC_LT,   KC_GT,     GEQ,                      XXXXXXX, KC_LCBR, KC_RCBR, KC_SLSH, KC_QUES, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //'--------------------------'  '--------------------------'
    ),

    [_NAVI] = LAYOUT_split_3x6_3(
    //.-----------------------------------------------------.                    .-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, WINSNIP, WSLEFT,  WSRIGHT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //'--------------------------'  '--------------------------'
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
    //.-----------------------------------------------------.                    .-----------------------------------------------------.
          RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                        //'--------------------------'  '--------------------------'
    )
};

layer_state_t layer_state_set_user(layer_state_t state)
{
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case CPPCOMM:
            if (record->event.pressed) {
                SEND_STRING("//");
            }
            return false;
        case COLCOL:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case LEQ:
            if (record->event.pressed) {
                SEND_STRING("<=");
            }
            return false;
        case GEQ:
            if (record->event.pressed) {
                SEND_STRING(">=");
            }
            return false;
    }
    return true;
}

// If you press a dual-role key, press another key, and then release the dual-role key,
// all within the tapping term, the dual-role key will perform its tap action. If the
// `HOLD_ON_OTHER_KEY_PRESS` option is enabled, the dual-role key will also perform its
// hold action instead.
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case LT(_LOWER, KC_DEL):
            // Since my lower key is used to access characters, and it also acts as
            // "Delete" when tapped, I need it to prefer the hold action if another
            // key is pressed because chances are, I'm not trying to press "Delete"
            // in the middle of a bunch of keystrokes.
        case LT(_RAISE, KC_ENT):
            // Since my raise key is used to access characters, and it also acts as
            // "Enter" when tapped, I need it to prefer the hold action if another
            // key is pressed because chances are, I'm not trying to press "Enter"
            // in the middle of a bunch of keystrokes.
            return true;
        default:
            return false;
    }
}

// If you press a dual-role key, tap another key (press and release) and then release
// the dual-role key, all within the tapping term, the dual-role key will perform its
// tap action by default. If the `PERMISSIVE_HOLD` option is enabled, the dual-role
// key will perform its hold action instead.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
    // I'm using macros for the home-row modifiers because permissive hold should
    // always be off for them, regardless of what they are. However, for the other
    // keys, I'm specifying the exact keys that should be effected.
    switch (keycode) {
        case MOD_A:
        case MOD_S:
        case MOD_D:
        case MOD_F:
        case MOD_J:
        case MOD_K:
        case MOD_L:
        case MOD_SC:
        case LT(_NAVI, KC_SPC):
            // Since my left space is used to access my navigation keys when held,
            // I tend to accidentally trigger some of the navigation keys when I'm
            // typing quickly because I'll be a little sloppy with the space key.
            // So, I'm going to experiment with turning permissive hold off for just
            // this key, assuming that I won't be trying to use my navigation keys
            // super quickly.
            return false;
        default:
            return true;
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void)
{
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record)
{
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
            record->event.key.row, record->event.key.col,
            keycode, name);
}

void oled_render_keylog(void)
{
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status)
{
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}
#endif // OLED_ENABLE
