#include "koehr.h"

/*
 * Simple calculator inside your keyboard!
 * Usage: hold down KC_CALC and type simple formula, like 4*2=
 * Result will be printed together with =
 * 
 * Numbers and Operators will only be recorded while KC_CALC is pressed.
 * Only positive numbers and + - * / are supported. No brackets.
 */
 

static int result = 0;
static int currentNumber = 0;
static char op = 0;
static bool active = false;
static char resultString[13];

void calc(void) {
    switch (op)
    {
      case KC_EQUAL:
        result += currentNumber;
        break;
      case KC_MINUS:
        result -= currentNumber;
        break;
      case KC_8:
        result *= currentNumber;
        break;
      case KC_SLASH:
        result /= currentNumber;
        break;
    }
    currentNumber = 0;
}

bool process_record_calculator(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_CALC) {
      active = record->event.pressed;
      return true;
    }

    if (!active) return true;

    // check if shift key is pressed
    bool is_capital = ( keyboard_report->mods & (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)) );

    if (op == 0) op = KC_EQUAL;

    // split by capitalisation because some operators are number keys
    if (!is_capital) {
        switch (keycode) {
          case KC_0:
          case KC_1:
          case KC_2:
          case KC_3:
          case KC_4:
          case KC_5:
          case KC_6:
          case KC_7:
          case KC_8:
          case KC_9:
            currentNumber = currentNumber * 10 + (keycode - KC_1) + 1;
            break;
          case KC_MINUS: // minus
          case KC_SLASH: // division
            calc();
            op = keycode;
            break;
          case KC_EQUAL: // result
            calc();
            snprintf(resultString, 13, "=%d ", result);
            send_string(resultString);

            result = 0;
            op = KC_EQUAL;
            return false;
        }
    } else {
        switch (keycode) {
          case KC_EQUAL: // plus
          case KC_8: // multiply
            calc();
            op = keycode;
            break;
        }
    }

    return true;
}
