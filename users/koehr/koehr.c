#include "koehr.h"
#include "version.h"

void matrix_init_user (void) {
#ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX); // sets linux unicode input
#endif
    set_single_persistent_default_layer(LBASE); // sets default layer
}

#ifdef UNICODE_ENABLE
bool unicode_key(uint32_t keycode) {
    unicode_input_start();
    register_hex(keycode);
    unicode_input_finish();
    return false;
}
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // key release is uninteresting
    if (keycode != KC_CALC && !record->event.pressed) return true;

    // check if shift key is pressed
    bool is_capital = ( keyboard_report->mods & (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)) );

    switch (keycode) {
        // Debugging
        case VRSN:
           SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
           return false;

// handle unicode characters more naturally:
// send capital letter if shift is pressed, small letter otherwise
#ifdef UNICODE_ENABLE
        // Turkish letters
        case TUR_A:
            return unicode_key(is_capital ? KCC_TUR_A : KCS_TUR_A);
        case TUR_C:
            return unicode_key(is_capital ? KCC_TUR_C : KCS_TUR_C);
        case TUR_G:
            return unicode_key(is_capital ? KCC_TUR_G : KCS_TUR_G);
        case TUR_I:
            return unicode_key(is_capital ? KCC_TUR_I : KCS_TUR_I);
        case TUR_O:
            return unicode_key(is_capital ? KCC_TUR_O : KCS_TUR_O);
        case TUR_S:
            return unicode_key(is_capital ? KCC_TUR_S : KCS_TUR_S);
        case TUR_U:
            return unicode_key(is_capital ? KCC_TUR_U : KCS_TUR_U);

        // German letters
        case GER_A:
            return unicode_key(is_capital ? KCC_GER_A : KCS_GER_A);
        case GER_O:
            return unicode_key(is_capital ? KCC_GER_O : KCS_GER_O);
        case GER_U:
            return unicode_key(is_capital ? KCC_GER_U : KCS_GER_U);
        case GER_S:
            return unicode_key(is_capital ? KCC_GER_S : KCS_GER_S);
#endif
    }

    return process_record_calculator(keycode, record);
}
