// Copyright 2034 MJarkas
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};


// Enable Layers
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LGUI_T(KC_S)
#define HOME_D LALT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K LALT_T(KC_K)
#define HOME_L RGUI_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
    * QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  |   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|-MUTE+ |    |-MUTE+ |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

  [0] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,   KC_7,    KC_8,    KC_9,      KC_0,      KC_BSPC,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,   KC_U,    KC_I,    KC_O,      KC_P,      KC_BSLS,
    KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                         KC_H,   HOME_J,  HOME_K,  HOME_L,    HOME_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,      KC_MUTE, KC_N,   KC_M,    KC_COMM, KC_DOT,    KC_SLSH,   KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, MO(1), KC_SPC,       KC_ENT,  MO(2),  KC_RCTL, KC_RALT, KC_RGUI
  ),


  /*
    * RAISE
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |  F1  |  F2  |  F3  |  F4  |   F5 |                    |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |
    * |--------+------+------+------+------+----|                    |------+------+------+------+------+------|
    * |  ESC |   1  |  2   |   3  |  4   |   5  |                    |  6   |   7  |   8  |   9  |   0   | F12 |
    * |--------+------+------+------+------+----|                    |------+------+------+------+------+------|
    * |      |   !  |  @   |  Del |  $   |   %  |-------.    ,-------|  ^   |   &  |   *  |   (  |   )  |  |   |
    * |------+------+------+------+------+------|-MUTE+ |    |-MUTE+ |------+------+------+------+------+------|
    * |LShift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |      | /Enter  /       \Space \  |      | RAlt | RCTR | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

  [1] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_BSLS, KC_LCBR, KC_LBRC, KC_DEL,  KC_MINS, KC_PPLS,                        KC_EQL,  KC_UNDS, KC_TRNS, KC_RBRC, KC_RCBR, KC_SLSH,
      KC_LSFT, KC_LPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_MUTE,      KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RPRN, KC_RSFT,
                        KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS, KC_SPC,       KC_ENT,  KC_TRNS, KC_RCTL, KC_RALT, KC_RGUI
  ),


  /* LOWER
    * ,-----------------------------------------.                    ,------------------------------------------.
    * |      |      |      |      |      |      |                    | MCL  | MCR  |      |       |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+-------+------+------|
    * |      |      |      |      |      |      |                    | ML   | MD   |  MU  |  MR   |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+-------+------+------|
    * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right |      |      |
    * |------+------+------+------+------+------|-MUTE+ |    |-MUTE+ |------+------+------+------+------+-------|
    * |      |      |      |      |      |      |-------|    |-------|      |      |      |       |      |      |
    * `-----------------------------------------/       /     \      \------------------------------------------'
    *            |      |      |      |      | / Enter /       \Space \  |      |      |      |      |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

  [2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS
  )


};


#ifdef ENCODER_ENABLE
/*
 * encoder_update_user will be called by QMK every time the
 * encoder is turned.
 *
 * index: index of the encoder
 * clockwise: the direction of the encoder. true -> clockwise
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // First (right) encoder
    if (clockwise) {
      tap_code(KC_PGDN); // Page down
    } else {
      tap_code(KC_PGUP); // Page up
    }
  } else if (index == 1) { // Second (left) encoder
    if (clockwise) {
      tap_code(KC_VOLD); // Volume down
    } else {
      tap_code(KC_VOLU); // Volume up
    }
  }

  return false;
}
#endif

#ifdef OLED_ENABLE
/*
 * oled_task_kb will be called at the start of oled_task,
 * weak function overridable by the user
 *
 */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {

  static const char PROGMEM raw_logo[] = {
    0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,255,255,255,
    56,248,248,248,248,248,224,  0,  3,  3,  3,  3,  0,192,240,248,248,248,248, 56, 24,  0,  0,  0,  0,  0,  0, 24, 56,248,248,248,248, 56, 24,  0,  0,  0,  0,  0,192,248,248,248,248,224,128,  0,  0,  0,  0,  0, 24, 56,248,248,248,248, 56, 56, 56, 56,120,248,240,240,192,  0, 24, 56,248,248,248,248, 24, 24,128,192,248,248,248,120, 56, 24,  0,  0,  0,  0,  0,  0,128,224,248,248,248,248,192,  0,  0,  0,  0,  0,255,255,255,191,255,239,255,255,255,255,239,159,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,255,255,255,
    0,255,255,255,255, 15, 63,255,252,240,192,248,254,255, 31,  7,255,255,255,  0,  0,  0,192,192,192,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,224,248,255,255,255,227,225,239,255,255,252,224,128,  0,  0,  0,  0,255,255,255,255, 28, 28, 60,252,254,255,207, 15,  3,  0,  0,  0,255,255,255,255, 62, 31,127,255,251,225,192,128,  0,  0,  0,  0,  0,128,240,252,255,255,239,225,227,255,255,255,248,224,  0,  0,255,255,255,252,251,251,247,247,255,255,239,223,127,255,255,255,  0,  0, 28, 28, 28, 28, 28, 31, 31, 31,
    28, 31, 31, 31, 31, 28, 28,  0,  7, 15, 15, 15,  3,  0, 28, 28, 31, 31, 31, 28, 28,  0,  7, 15, 15, 31, 28, 28, 30, 31, 15, 15,  3,  0,  0, 28, 31, 31, 31, 31, 28,  0,  0,  0,  0,  0, 29, 31, 31,159,156,156,156, 28, 31, 31, 31, 31, 28, 12,  0,  1,135,159,159, 30, 28,  0, 28, 28, 31, 31, 31, 31,156,140,128,128,159, 31, 31, 31, 30, 28, 28, 28, 28, 31, 31, 31, 31,  0,  0,  0,  0,  0, 12, 31, 31, 31, 31, 28, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 61, 62, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};
oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOW"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

bool oled_task_user(void) {
  update_log();
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    return true;
}

#endif
