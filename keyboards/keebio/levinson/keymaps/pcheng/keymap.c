#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY     0
#define _LOWER      1
#define _RAISE      2
#define _COLEMAK_DH 3
#define _DVORAK     4
#define _ADJUST     16

enum custom_keycodes
{
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    DUBCOL,
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)

#define LOWDEL  MT(LOWER, KC_DEL)
#define CTLESC  LCTL_T(KC_ESC)
#define WINSNIP S(G(KC_S))
#define WSLEFT  C(G(KC_LEFT))
#define WSRIGHT C(G(KC_RIGHT))
#define CTLALTD C(A(KC_DEL))

/* TODO: Add in a macro for comments because I doin't like reaching for the slash key */


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
    * |      | Ctrl | GUI  | Alt  |Lower*|Space |      |Enter |Raise*| Left | Down |  Up  |Right |
    * '-----------------------------------------'      '-----------------------------------------'
    *
    * - Ctrl acts as Esc when tapped
    * - Lower acts as Del when tapped
    * - Raise acts as Backspace when tapped
    */
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,               KC_I,    KC_O,    KC_P,    KC_BSPC, \
        CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,               KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,               KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
        XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, LOWDEL,  KC_SPC,  KC_ENT,  MT(RAISE, KC_BSPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
    ),

    /* Lower
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |Hangul| Snip | WS<- | WS-> |      |      | Left | Down |  Up  |Right |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | Caps |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      | Home | PgDn | PgUp | End  |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_LOWER] = LAYOUT_ortho_4x12( \
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
        _______, KC_HAEN, WINSNIP, WSLEFT,  WSRIGHT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
    ),

    /* Raise
    * .-----------------------------------------.      .-----------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   |  |   \  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |   _  |   -  |   +  |   =  |  <=  |      |      |   (  |   )  |   [  |   ]  |  `   |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |  ::  |  ->  |   <  |   >  |  >=  |      |      |   {  |   }  |   /  |   ?  |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    [_RAISE] = LAYOUT_ortho_4x12( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______, \
        _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  _______, _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_GRV,  \
        _______, DUBCOL, _______, KC_LT,   KC_GT,   _______, _______, KC_LCBR, KC_RCBR, KC_SLSH, KC_QUES, _______, \
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
    * |Adjust| Ctrl | GUI  | Alt  |Lower |Space |      |Space |Raise | Left | Down |  Up  |Right |
    * '-----------------------------------------'      '-----------------------------------------'
    */
    /*
    [_COLEMAK_DH] = LAYOUT_ortho_4x12( \
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
        CLTESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
        ADJUST,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
    )
    */

    /* Dvorak
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    /*
    [_DVORAK] = LAYOUT_ortho_4x12( \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
      KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
      ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
    ),
    */

    /* Adjust (Lower + Raise)
    * .-----------------------------------------.      .-----------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |Reset |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * | CAD  |      |      |      |      |      |      |      |Qwerty|Colemk|Dvorak|      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|      |------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * '-----------------------------------------'      '-----------------------------------------'
    *
    * - CAD = Ctrl + Alt + Del
    */
    [_ADJUST] =  LAYOUT_ortho_4x12( \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
      CTLALTD, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case DUBCOL:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
    }
    return true;
}