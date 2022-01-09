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
    CPPCOMM,
    COLCOL,
    ARROW,
    LEQ,
    GEQ,
};

#define BASE     TO(_QWERTY)
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define ADJUST   MO(_ADJUST)

#define WINSNIP  S(G(KC_S))
#define WSLEFT   C(G(KC_LEFT))
#define WSRIGHT  C(G(KC_RIGHT))
#define CTLALTD  C(A(KC_DEL))

/* TODO: Move some macros onto the lower layer
 * TODO: Add shift word using tap dance on the shift key
 * TODO: Add tap dance on the bottom left key (maybe Ctrl + Alt + Del?)
 */

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
    * |      | Ctrl | GUI  | Alt  |Lower*|Space*|      |Space |Raise |Left* | Down |  Up  |Right |
    * '-----------------------------------------'      '-----------------------------------------'
    *
    * - Ctrl acts as Esc when tapped
    * - Lower acts as Del when tapped
    * - Left space enables navigation layer when held
    * - Left arrow enables function layer when held
    */
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,         KC_Q,    KC_W,         KC_E,         KC_R,                KC_T,               KC_Y,    KC_U,         KC_I,              KC_O,            KC_P,            KC_BSPC, \
        LCTL_T(KC_ESC), KC_A,    LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F),        KC_G,               KC_H,    LCTL_T(KC_J), RSFT_T(KC_K),      LALT_T(KC_L),    RGUI_T(KC_SCLN), KC_QUOT, \
        KC_LSFT,        KC_Z,    KC_X,         KC_C,         KC_V,                KC_B,               KC_N,    KC_M,         KC_COMM,           KC_DOT,          KC_SLSH,         KC_ENT , \
        XXXXXXX,        KC_LCTL, KC_LGUI,      KC_LALT,      LT(_LOWER, KC_DEL),  LT(_NAVI, KC_SPC),  KC_SPC,  RAISE,        LT(_FNC, KC_LEFT), KC_DOWN,         KC_UP,           KC_RGHT  \
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
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
        _______, KC_HAEN, _______, _______, _______, _______, _______, ARROW,   CPPCOMM, _______, _______, _______, \
        KC_CAPS, _______, _______, _______, _______, _______, _______, COLCOL,  _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
    * |      | F12  |  F7  |  F8  |  F9  |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      | F11  |  F4  |  F5  |  F6  |      |      |      | Ctrl |Shift | Alt  | Gui  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      | F10  |  F1  |  F2  |  F3  |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_FNC] = LAYOUT_ortho_4x12( \
        _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI, _______, \
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______, _______, _______, _______, \
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
        KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
        LCTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
        _______,        KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
    ),

    /* Adjust (Lower + Raise)
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | CAD  |      |      |      |      |      |      |      | Rec1 |Macro1|      | Stop |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |Numpad|      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |(Used)|      |      |      |(Used)|Qwerty|Colemk|      |      |
    * '-----------------------------------------'      '-----------------------------------------'

    * - CAD = Ctrl + Alt + Del
    */
    [_ADJUST] = LAYOUT_ortho_4x12( \
      _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, \
      CTLALTD, _______, _______, _______, _______, _______, _______, DM_REC1,     DM_PLY1, _______, DM_RSTP, _______, \
      _______, _______, _______, _______, _______, _______, _______, TG(_NUMPAD), _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______,     QWERTY,  COLEMAK, _______, _______  \
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
        case LCTL_T(KC_ESC):
            // I need this key to prefer the hold action when I roll, which I often
            // do with "Ctrl + *" shortcuts.
        case LT(_LOWER, KC_DEL):
            // Since my lower key is used to access characters and also acts as
            // "Delete" when tapped, I need it to prefer the hold action if another
            // key is pressed because chances are, I'm not trying to press "Delete"
            // in the middle of a bunch of keystrokes.
        case LT(_RAISE, KC_ENT):
            // Since my raise key is used to access characters, and also acts as
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
    // TODO Flip the logic here. Keys that need permissive hold are the ones that
    // I will combo quickly: `LOWER`, `RAISE`, `CTLESC`.
    // Seems like it's the same as the above!
    switch (keycode) {
        case LGUI_T(KC_A):
        case LALT_T(KC_S):
        case LSFT_T(KC_D):
        case LCTL_T(KC_F):
        case LCTL_T(KC_J):
        case RSFT_T(KC_K):
        case LALT_T(KC_L):
        case RGUI_T(KC_SCLN):
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
