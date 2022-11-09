 /* Copyright HarshitGoel96 2020
  * With permission from mattdibi, the original maintainer of the Redox hardware.
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */ 
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _BASE 0
#define _MOVE 1
#define _NUMB 2
#define _NUMPAD 3
#define _SYMB 4

enum custom_keycodes {
    BASE = SAFE_RANGE,
    MOVE,
    NUMB,
    NUMPAD,
    SYMB,
};

enum {
    TD_SCLN_QUOT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x5_3_encoder(
	KC_Q, KC_W, KC_E, KC_R, KC_T, 				KC_Y, KC_U, KC_I, KC_O, KC_P, 
	KC_A, KC_S, KC_D, KC_F, KC_G, 				KC_H, KC_J, KC_K, KC_L, TD(TD_SCLN_QUOT), 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_AUDIO_MUTE, 	KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
	KC_LALT, MO(1), MO(4), TO(1), 				TO(2), LT(4,KC_LGUI), KC_SPC, LT(2,KC_DEL)
),

[_MOVE] = LAYOUT_split_3x5_3_encoder(
	KC_ESC, LGUI(KC_TAB), SGUI(KC_S), LALT(KC_F4), LSFT(KC_INS), 		KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSPC,
	KC_TAB, KC_CUT, KC_COPY, KC_PSTE, KC_FIND,	 			KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
	KC_LSFT, KC_PSCR, KC_NO, KC_NO, TO(3), KC_AUDIO_MUTE,	 		LSA(KC_N), KC_NO, KC_CAPS, KC_NUM, KC_INS,
	KC_TRNS, KC_TRNS, KC_TRNS, TO(0), 					TO(0), KC_LCTL, KC_TRNS, KC_NO 
),

[_NUMB] = LAYOUT_split_3x5_3_encoder(
	KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 				KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12, KC_AUDIO_MUTE, 	KC_INS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, TO(0),				TO(0), KC_TRNS, KC_RCTL, KC_RALT),

[_NUMPAD] = LAYOUT_split_3x5_3_encoder(
	TO(0), KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PMNS, KC_7, KC_8, KC_9, KC_PPLS,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PAST, KC_4, KC_5, KC_6, KC_PDOT,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_AUDIO_MUTE,		KC_PSLS, KC_1, KC_2, KC_3, KC_PEQL,
	KC_NO, KC_BSPC, KC_ENT, KC_NO, 					KC_NO, KC_NO, KC_NO, KC_0
),

[_SYMB] = LAYOUT_split_3x5_3_encoder(
	KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, 			KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC,
	KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, 			KC_UNDS, KC_PLUS, KC_MINS, KC_EQL, KC_DQUO,
	KC_TILD, KC_GRV, KC_NO, KC_NO, KC_NO, KC_AUDIO_MUTE, 		KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS,
	KC_TRNS, KC_NO, KC_TRNS, KC_NO, 				KC_NO, KC_NO, KC_NO, KC_NO
),

};

enum combos {
//  AB_ESC,
  JK_ESC,
//  QW_SFT,
  MCOMMA_NUM,
//  SD_LAYER,
};

//const uint16_t PROGMEM ab_combo[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
//const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
//const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
//  [AB_ESC] = COMBO(ab_combo, KC_ESC),
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
//  [QW_SFT] = COMBO(qw_combo, KC_LSFT)
  [MCOMMA_NUM] = COMBO(mcomma_combo, OSL(2))
//  [SD_LAYER] = COMBO(sd_combo, MO(_LAYER)),
};

/*
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
//    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
//    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
//    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
*/
