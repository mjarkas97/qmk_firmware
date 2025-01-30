// Copyright 2034 MJarkas
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


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
    KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5,                          KC_6,  KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC, 
    KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,                          KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS, 
    KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G,                          KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, 
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,  KC_MUTE,       KC_MUTE, KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
          KC_LGUI, KC_LALT, KC_LCTL, MO(1), KC_SPC,        KC_ENT,  MO(2), KC_RCTL, KC_RALT, KC_RGUI
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
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12, 
      KC_NO,   KC_EXLM, KC_AT,   KC_DEL,  KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, 
      KC_LSFT, KC_EQL,  KC_MINS, KC_PPLS, KC_LCBR, KC_RCBR, KC_MUTE,  KC_MUTE, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_RSFT, 
                        KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS, KC_SPC,   KC_ENT,  KC_NO,   KC_RCTL, KC_RALT, KC_RGUI
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
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_BTN1, KC_BTN2, KC_NO,   KC_NO,   KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE,     KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, 
                  KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT,      KC_SPC,  KC_TRNS, KC_NO,   KC_NO,   KC_NO
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
    } 
    else {
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

bool oled_task_kb(void) {
  
  if (!oled_task_user()) {
    return false;
  }

  if (is_keyboard_master()) {
    
    print_status_narrow();

  } else {

    render_logo();

  }

  return true;
}

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {

    if (is_keyboard_master()) {

        return OLED_ROTATION_270;

    }

    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_P(PSTR("Lower"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

#endif