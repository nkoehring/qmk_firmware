#ifndef USERSPACE
#define USERSPACE

#include QMK_KEYBOARD_H

// Layers
#define LBASE 0  // Base layer
#define LSPCL 1  // special characters and mouse control layer

#ifdef UNICODE_ENABLE
// general symbols
#define GEN_DGC UC(0x2103) // ℃.
#define GEN_DGF UC(0x2109) // ℉.
#define GEN_KEL UC(0x221A) // K
// currency symbols
#define CUR_LIR UC(0x20ba) // ₺
#define CUR_BIT UC(0x20bf) // ₿
#define CUR_EUR UC(0x20ac) // €
#define CUR_BPN UC(0x00a3) // £
#define CUR_CUR UC(0x00a4) // ¤
#define CUR_YEN UC(0x00a5) // ¥
// special letters (KCS = Key Code Small, KCC = Key Code Capital)
// not used directly in the kymap but translated by the key capture function
// turkish
#define KCS_TUR_A (0x00e2) // â
#define KCC_TUR_A (0x00c2) // Â
#define KCS_TUR_C UC(0x00e7) // ç
#define KCC_TUR_C UC(0x00c7) // Ç
#define KCS_TUR_G UC(0x011f) // ğ
#define KCC_TUR_G UC(0x011e) // Ğ
#define KCS_TUR_I UC(0x0131) // ı
#define KCC_TUR_I UC(0x0130) // İ
#define KCS_TUR_O UC(0x00f6) // ö
#define KCC_TUR_O UC(0x00d6) // Ö
#define KCS_TUR_S UC(0x015f) // ş
#define KCC_TUR_S UC(0x015e) // Ş
#define KCS_TUR_U UC(0x00fc) // ü
#define KCC_TUR_U UC(0x00dc) // Ü
// german letters
#define KCS_GER_A UC(0x00e4) // ä
#define KCC_GER_A UC(0x00c4) // Ä
#define KCS_GER_O UC(0x00f6) // ö
#define KCC_GER_O UC(0x00d6) // Ö
#define KCS_GER_U UC(0x00fc) // ü
#define KCC_GER_U UC(0x00dc) // Ü
#define KCS_GER_S UC(0x00df) // ß
#define KCC_GER_S UC(0x1e9e) // ẞ

#else
#define CUR_LIR KC_NO
#define CUR_BIT KC_NO
#define CUR_EUR KC_NO
#define CUR_BPN KC_NO
#define CUR_YEN KC_NO
#endif

enum custom_keycodes {
    // Debugging
    VRSN = SAFE_RANGE,
    // Turkish letters
    TUR_A,
    TUR_C,
    TUR_G,
    TUR_I,
    TUR_O,
    TUR_S,
    TUR_U,
    // German letters
    GER_A,
    GER_O,
    GER_U,
    GER_S,
};

#define LAYOUT_ergodox_wrapper(...) LAYOUT_ergodox(__VA_ARGS__)

/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  `~  |           |  =+  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  [{  |           |  ]}  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | MO(1)  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |  '     |
 * |--------+------+------+------+------+------| LGUI |           | RCTL |------+------+------+------+------+--------|
 * |  LS/(  |   Z  |   X  |   C  |   V  |   B  |------|           |------|   N  |   M  |   ,  |   .  |  Up  |  RS/)  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |      | VRSN | Calc | LAlt |                                       | RAlt |   /  | Left | Down | Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | Ins  |PRNTSC|       |SCRLCK| Pause |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 | Space| Del  |------|       |------| Bcksp |Enter |
 *                                 |      |      | End  |       | PgDn |       |      |
 *                                 `--------------------'       `----------------------'
 */
#define BASE_LAYOUT \
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_GRV,  \
  KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC, \
  MO(1),     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,            \
  KC_LSPO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LGUI, \
  KC_LCTL,  KC_NO,   VRSN,KC_CALC,KC_LALT, \
                                             KC_INS, KC_PSCR,\
                                                     KC_HOME,\
                                     KC_SPC, KC_DEL, KC_END, \
\
  KC_EQL,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, \
  KC_RBRC,  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS, \
            KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT, \
  KC_RCTL,  KC_N,   KC_M,   KC_COMM,KC_DOT, KC_UP,  KC_RSPC, \
                 KC_RALT,   KC_SLSH,KC_LEFT,KC_DOWN,KC_RGHT, \
  KC_SLCK, KC_PAUS, \
  KC_PGUP,               \
  KC_PGDN,KC_BSPC, KC_ENT


/* Keymap 1: Special keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |   ℃.   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |   €  |      |      |      |           |      |   ¥  |   Ü  |   İ  |   Ö  |   £  |   ℉.   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  TRNS  |   Ä  |   Ş  |      |      |   Ğ  |------|           |------|      |      |      |      |      | MWH_UP |
 * |--------+------+------+------+------+------| LGUI |           | RCTL |------+------+------+------+------+--------|
 * | LShift |   ß  |      |   Ç  |      |      |------|           |------|      |      |MBtn2 |MBtn3 | MUp  |MWH_DWN |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL |      |      |      | LAlt |                                       | RAlt |MBtn1 |MLeft |MDown |MRight |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       | MPrv | MNxt |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Play |------|------|
 *                                 |BRIT+ |BRIT- |------|       |------| VOL- | Vol+ |
 *                                 |      |      |      |       | Mute |------|------|
 *                                 `--------------------'       `--------------------'
 */
#define SPECIAL_KEYS \
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO, \
  KC_NO,   KC_NO,   KC_NO, CUR_EUR,   KC_NO,   KC_NO,   KC_NO, \
  KC_TRNS, GER_A,   TUR_S,   KC_NO,   KC_NO,   TUR_G,          \
  KC_LSFT, GER_S,   KC_NO,   TUR_C,   KC_NO,   KC_NO, KC_LGUI, \
  KC_LCTL, KC_NO,   KC_NO,   KC_NO,  KC_LALT, \
                                              KC_NO,  KC_NO,\
                                                      KC_NO, \
                                     KC_BRIU,KC_BRID, KC_NO,\
\
  KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, GEN_DGC, \
  KC_NO, CUR_YEN,   GER_U,   TUR_I,   GER_O, CUR_BPN, GEN_DGF, \
           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_WH_U, \
  KC_RCTL, KC_NO,   KC_NO, KC_BTN2, KC_BTN3, KC_MS_U, KC_WH_D, \
                  KC_RALT, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, \
  KC_MPRV, KC_MNXT, \
  KC_MPLY,               \
  KC_MUTE,KC_VOLD, KC_VOLU

bool process_record_calculator(uint16_t, keyrecord_t*);
#endif
