#include QMK_KEYBOARD_H

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

enum keycodes
{
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    CPPCOMMENT,
    COLCOL,
    ARROW,
    LEQ,
    GEQ,
};

#define BASE     TO(_QWERTY)
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define ADJUST   MO(_ADJUST)

#define CTLESC   LCTL_T(KC_ESC)
#define WINSNIP  S(G(KC_S))
#define WSLEFT   C(G(KC_LEFT))
#define WSRIGHT  C(G(KC_RIGHT))
#define CTLALTD  C(A(KC_DEL))

#define LCHRM    LCTL_T(KC_F)
#define LSHRM    LSFT_T(KC_D)
#define LAHRM    LALT_T(KC_S)
#define LGHRM    LGUI_T(KC_A)

#define RCHRM    LCTL_T(KC_J)    // For some reason, right control doesn't work...
#define RSHRM    RSFT_T(KC_K)
#define RAHRM    LALT_T(KC_L)
#define RGHRM    RGUI_T(KC_SCLN)

/* TODO: Move some macros onto the lower layer
 * TODO: Add shift word using tap dance on the shift key
 * TODO: Add tap dance on the bottom left key (maybe Ctrl + Alt + Del?)
 */

enum tapdance
{
    SAFE_RESET
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count >= 3) {
        reset_keyboard();
        reset_tap_dance(state);
    }
}

qk_tap_dance_action_t tap_dance_actions[] =
{
    [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    /* Qwerty
    * .-----------------------------------------.      .-----------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | Ctrl*|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      | Ctrl | GUI  | Alt  |Lower*|Space*|      |Space |Raise*|Left* | Down |  Up  |Right |
    * '-----------------------------------------'      '-----------------------------------------'
    *
    * - Ctrl acts as Esc when tapped
    * - Lower acts as Del when tapped
    * - Raise acts as Backspace when tapped
    * - Left space moves to navigation layer when held
    * - Left moves to function layer when held
    */
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,                KC_T,               KC_Y,    KC_U,               KC_I,              KC_O,    KC_P,    KC_BSPC, \
        LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,                KC_G,               KC_H,    KC_J,               KC_K,              KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,                KC_B,               KC_N,    KC_M,               KC_COMM,           KC_DOT,  KC_SLSH, KC_ENT , \
        XXXXXXX,        KC_LCTL, KC_LGUI, KC_LALT, LT(_LOWER, KC_DEL),  LT(_NAVI, KC_SPC),  KC_SPC,  LT(_RAISE, KC_ENT), LT(_FNC, KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT  \
    ),

    /* Lower
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |Hangul|      |      |      |      |      |      |  ->  |  //  |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | Caps |      |      |      |      |      |      |      |  ::  |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_LOWER] = LAYOUT_ortho_4x12( \
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    _______, \
        _______, KC_HAEN, _______, _______, _______, _______, _______, ARROW,   CPPCOMMENT, _______, _______, _______, \
        KC_CAPS, _______, _______, _______, _______, _______, _______, COLCOL,  _______,    _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______  \
    ),

    /* Raise
    * .-----------------------------------------.      .-----------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   |  |   \  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |   _  |   -  |   +  |   =  |  <=  |      |      |   (  |   )  |   [  |   ]  |  `   |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |   <  |   >  |  >=  |      |      |   {  |   }  |   /  |   ?  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_RAISE] = LAYOUT_ortho_4x12( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLASH, _______, \
        _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  LEQ,     _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,   KC_GRV,  \
        _______, _______, _______, KC_LT,   KC_GT,   GEQ,     _______, KC_LCBR, KC_RCBR, KC_SLSH, KC_QUES,   _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______  \
    ),

    /* Navigation
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |      |      |      |      |      |      | Home | PgDn | PgUp | End  |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      | Snip | WS<- | WS-> |      |      | Left | Down |  Up  |Right |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_NAVI] = LAYOUT_ortho_4x12( \
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
        _______, _______, WINSNIP, WSLEFT,  WSRIGHT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

    /* Numpad
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |      |      |      |      |      |      |      |   7  |   8  |   9  |   =  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | BASE |      |      |      |      |      |      |   /  |   4  |   5  |   6  |   -  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |   *  |   1  |   2  |   3  |   +  |Enter |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |   0  |   ,  |   .  |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_NUMPAD] = LAYOUT_ortho_4x12( \
        _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8,    KC_9,   KC_EQL,  _______, \
        BASE,    _______, _______, _______, _______, _______, KC_SLSH, KC_4, KC_5,    KC_6,   KC_MINS, _______, \
        _______, _______, _______, _______, _______, _______, KC_ASTR, KC_1, KC_2,    KC_3,   KC_PLUS, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_0, KC_COMM, KC_DOT, _______, _______  \
    ),

    /* Function layer
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |      |      |      | Ctrl |Shift | Alt  | Gui  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |  F9  | F10  | F11  | F12  |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_FNC] = LAYOUT_ortho_4x12( \
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, RCHRM,   RSHRM,   RAHRM,   RGHRM,   _______, \
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

    /* Colemak_DH
    * .-----------------------------------------.      .-----------------------------------------.
    * | Tab  |   Q  |   W  |   F  |   P  |   B  |      |   J  |   L  |   U  |   Y  |   ;  | Bksp |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |CltEsc|   A  |   R  |   S  |   T  |   G  |      |   M  |   N  |   E  |   I  |   O  |  '   |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   D  |   V  |      |   K  |   H  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      | Ctrl | GUI  | Alt  |Lower |Space |      |Space |Raise | Left | Down |  Up  |Right |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_COLEMAK] = LAYOUT_ortho_4x12( \
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
        CLTESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
        _______, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
    ),

    /* Adjust (Lower + Raise)
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |Reset |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | CAD  |      |      |      |      |      |      |      |Qwerty|Colemk|Macro1|Macro2|      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |Numpad| Stop | Rec1 | Rec2 |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    *
    * - CAD = Ctrl + Alt + Del
    */
    [_ADJUST] = LAYOUT_ortho_4x12( \
      _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, TD(SAFE_RESET), \
      CTLALTD, _______, _______, _______, _______, _______, _______, QWERTY,      COLEMAK, DM_PLY1, DM_PLY2, _______,        \
      _______, _______, _______, _______, _______, _______, _______, TG(_NUMPAD), DM_RSTP, DM_REC1, DM_REC2, _______,        \
      _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______         \
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
        case CPPCOMMENT:
            if (record->event.pressed) {
                SEND_STRING("// ");
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
        case LT(_RAISE, KC_ENT):
            // Since my raise key is currently used to access symbols and it also acts
            // as "Enter" when tapped, I need it prefer the hold action if another
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
    switch (keycode) {
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
