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
     * |------+------+------+------+------+------|       |    |-MUTE+ |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LCTR | LAlt |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RCTR | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [0] = LAYOUT(
      KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5,                          KC_6,  KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC, 
      KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,                          KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS, 
      KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G,                          KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, 
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,  KC_NO,         KC_MUTE, KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
            KC_LGUI, KC_LCTL, KC_LALT, MO(1), KC_SPC,        KC_ENT,  MO(2), KC_RALT, KC_RCTL, KC_RGUI
    ),


    /*
     * COLEMAK
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |  F1  |  F2  |  F3  |  F4  |   F5 |                    |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |
     * |--------+------+------+------+------+----|                    |------+------+------+------+------+------|
     * |  ESC |   1  |  2   |   3  |  4   |   5  |                    |  6   |   7  |   8  |   9  |   0   | F12 |
     * |--------+------+------+------+------+----|                    |------+------+------+------+------+------|
     * |      |   !  |  @   |  Del |  $   |   %  |-------.    ,-------|  ^   |   &  |   *  |   (  |   )  |  |   |
     * |------+------+------+------+------+------|       |    |-MUTE+ |------+------+------+------+------+------|
     * |LShift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LCTR | LAlt |      | /Enter  /       \Space \  |      | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12, 
        KC_NO,   KC_EXLM, KC_AT,   KC_DEL,  KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, 
        KC_LSFT, KC_EQL,  KC_MINS, KC_PPLS, KC_LCBR, KC_RCBR, KC_NO,         KC_MUTE, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_RSFT, 
                          KC_LGUI, KC_LCTL, KC_LALT, KC_TRNS, KC_SPC,        KC_ENT,  KC_NO,   KC_RALT, KC_RCTL, KC_RGUI
    ),


    /* RAISE
     * ,-----------------------------------------.                    ,------------------------------------------.
     * |      |      |      |      |      |      |                    | MCL  | MCR  |      |       |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+-------+------+------|
     * |      |      |      |      |      |      |                    | ML   | MD   |  MU  |  MR   |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+-------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right |      |      |
     * |------+------+------+------+------+------|       |    |-MUTE+ |------+------+------+-------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |       |      |      |
     * `-----------------------------------------/       /     \      \------------------------------------------'
     *            |      |      |      |      | / Enter /       \Space \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [2] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_BTN1, KC_BTN2, KC_NO,   KC_NO,   KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, 
                      KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT,                    KC_SPC,  KC_TRNS, KC_NO,   KC_NO,   KC_NO
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

      tap_code(KC_VOLU); // Volume up

    } 
    else {

      tap_code(KC_VOLD); // Volume down

    }

  } else if (index == 1) { // Second (left) encoder

    if (clockwise) {

      tap_code(KC_VOLU); // Volume up

    } else {

      tap_code(KC_VOLD); // Volume down

    }

  }

  return false;
}
#endif