#include "pcheng.h"

/* TODO: Move some macros onto the lower layer
 * TODO: Add shift word using tap dance on the shift key
 * TODO: Add tap dance on the bottom left key (maybe Ctrl + Alt + Del?)
 */

#define LAYOUT_wrapper(...)    LAYOUT_ortho_4x12(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_QWERTY] = LAYOUT_wrapper(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
         KC_TAB, _________________QWERTY_L1_________________,        _________________QWERTY_R1_________________, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
         CTLESC, _____________QWERTY_MAC_MOD_L2_____________,        _____________QWERTY_MAC_MOD_R2_____________, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        KC_LSFT, _________________QWERTY_L3_________________,        _________________QWERTY_R3_________________,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
         GAMING, KC_LCTL, KC_LOPT, KC_LCMD, LWR_DEL, NAV_SPC,         KC_SPC,   RAISE,    FUNC, XXXXXXX, XXXXXXX, XXXXXXX
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    ),

    [_GAMING] = LAYOUT_wrapper(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
         KC_TAB, _________________QWERTY_L1_________________,        _________________QWERTY_R1_________________, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
         KC_ESC, _________________QWERTY_L2_________________,        _________________QWERTY_R2_________________,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        KC_LSFT, _________________QWERTY_L3_________________,        _________________QWERTY_R3_________________,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
           BASE, KC_LCTL, KC_LOPT, KC_LCMD,   LOWER,  KC_SPC,         KC_SPC,   RAISE,    FUNC, XXXXXXX, XXXXXXX, XXXXXXX
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    ),

    [_LOWER] = LAYOUT_wrapper(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
        _______, _________________LOWER_L1__________________,        _________________LOWER_R1__________________, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, _________________LOWER_L2__________________,        _________________LOWER_R2__________________, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, _________________LOWER_L3__________________,        _________________LOWER_R3__________________, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, __________________BLANK____________________,        __________________BLANK____________________, _______
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    ),

    [_RAISE] = LAYOUT_wrapper(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
        KC_TILD, _________________RAISE_L1__________________,        _________________RAISE_R1__________________, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, _________________RAISE_L2__________________,        _________________RAISE_R2__________________,  KC_GRV,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, _________________RAISE_L3__________________,        _________________RAISE_R3__________________, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, __________________BLANK____________________,        __________________BLANK____________________, _______
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    ),

    [_NAVI] = LAYOUT_wrapper(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
        XXXXXXX, __________________NO_OP____________________,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX,  SSCLIP,  MSLEFT, MSRIGHT, XXXXXXX,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, __________________NO_OP____________________,        __________________NO_OP____________________, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, __________BLANK__________,        __________BLANK__________, XXXXXXX, XXXXXXX, XXXXXXX 
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    ),

    [_NUMPAD] = LAYOUT_wrapper(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
        XXXXXXX, __________________NO_OP____________________,        ________________NUMPAD_R1__________________, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
           BASE, __________________NO_OP____________________,        ________________NUMPAD_R2__________________, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, __________________NO_OP____________________,        ________________NUMPAD_R3__________________,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, __________________BLANK____________________,        ________________NUMPAD_R4__________________, XXXXXXX
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    ),

    [_FUNC] = LAYOUT_wrapper(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
        XXXXXXX, __________________FUNC_L1__________________,        __________________NO_OP____________________, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, __________________FUNC_L2__________________,        ____________HOME_ROW_MOD_MAC_R_____________, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, __________________FUNC_L3__________________,        __________________NO_OP____________________, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        XXXXXXX, __________________BLANK____________________,        __________________BLANK____________________, XXXXXXX
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    ),

    [_ADJUST] = LAYOUT_ortho_4x12(
    //.-----------------------------------------------------.      .-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,        _______, DM_REC1, DM_PLY1, _______, DM_RSTP, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,        _______, NUMPAD,  _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______
    //'-----------------------------------------------------'      '-----------------------------------------------------'
    )
};
