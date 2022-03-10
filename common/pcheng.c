#include "pcheng.h"

// Allows the "Adjust" layer to be trigger by pressing both "Lower" and "Raise."
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_SLSL:
            if (record->event.pressed) {
                SEND_STRING("//");
            }
            return false;
        case KC_CLCL:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
        case KC_ARRW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case KC_LEQ:
            if (record->event.pressed) {
                SEND_STRING("<=");
            }
            return false;
        case KC_GEQ:
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
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
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
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Enable permissive hold for key combinations that I will
    // quickly combo and release.
    switch (keycode) {
        case LCTL_T(KC_ESC):
            // I need this key to prefer the hold action if I press any other key
            // while it is held down.
        case LT(_LOWER, KC_DEL):
            // Since my lower key is used to access characters and also acts as
            // "Delete" when tapped, I need it to prefer the hold action if another
            // key is tapped because chances are, I'm not trying to press "Delete"
            // in the middle of a bunch of keystrokes.
        case LT(_RAISE, KC_ENT):
            // Since my raise key is used to access characters, and also acts as
            // "Enter" when tapped, I need it to prefer the hold action if another
            // key is tapped because chances are, I'm not trying to press "Enter"
            // in the middle of a bunch of keystrokes.
            return true;
        default:
            return false;
    }
}
