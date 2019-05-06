/*
 * ERGODOX - US with special unicode support
 * Keymap by @koehr
 * inspired by @bbaserdems DVORAK layout
 * Most of the code is in the "user" directory.
 * Check qmk_firmware/users/koehr for the main part of the code
 */

#include QMK_KEYBOARD_H
#include "koehr.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LBASE] = LAYOUT_ergodox_wrapper(BASE_LAYOUT),
    [LSPCL] = LAYOUT_ergodox_wrapper(SPECIAL_KEYS)
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
    }

  return state;
};
