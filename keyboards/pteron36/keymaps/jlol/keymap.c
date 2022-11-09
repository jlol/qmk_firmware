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
//


enum {
    TD_SCLN_QUOT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};


enum custom_keycodes {
  _QWERTY,
  _RAISE,
  _LOWER,
  _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
    [_QWERTY] = LAYOUT_split_3x5_3_encoder(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LSFT_T(KC_SLSH),
                                   MO(1), KC_BSPC, MO(2), KC_SPC, KC_SPC,  KC_SPC,  KC_ENT,  KC_RALT
    ),
    [_RAISE] = LAYOUT_split_3x5_3_encoder(
        KC_F,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSPC, KC_SPC, KC_SPC, KC_SPC,  KC_SPC,  KC_ENT,  KC_RALT
    ),
    [_LOWER] = LAYOUT_split_3x5_3_encoder(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSPC, KC_SPC, KC_SPC, KC_SPC,  KC_SPC,  KC_ENT,  KC_RALT
    ),
    [_NUMPAD] = LAYOUT_split_3x5_3_encoder(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSPC, KC_SPC, KC_SPC, KC_SPC,  KC_SPC,  KC_ENT,  KC_RALT
    )
    */
[_QWERTY] = LAYOUT_split_3x5_3_encoder(
	KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
	KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_LBRC, 		KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
	MO(2), KC_BSPC, KC_ENT, MO(1), KC_RGUI, MO(3), KC_SPC, KC_DEL
	),

[_RAISE] = LAYOUT_split_3x5_3_encoder(
	KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_EQL, 
	KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_CAPS,  KC_LBRC,	RCTL(KC_RSFT), KC_LBRC, KC_RBRC, RGUI(KC_RSFT), KC_BSLS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_RALT
	),

[_LOWER] = LAYOUT_split_3x5_3_encoder(
	KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, 
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12,  KC_LBRC,	KC_INS, KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_RALT
	),

[_NUMPAD] = LAYOUT_split_3x5_3_encoder(
	KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, 
	KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSLS, KC_PPLS, KC_MINS, KC_EQL, KC_NO, 
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC,	KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_NO, 
	KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
	) 
};

/*
enum combos { 
  A_S_RCTL,
  A_D_RALT,
  A_F_LCTLRALT,
  A_G_ESC,
  J_K_RCTL,
  J_L_RALT,
  J_SCLN_LCTLRALT,
  A_Q_ESC,
  E_I_INS,
  S_I_RSFTINS,
  C_T_LCTLF5,
  
};

const uint16_t PROGMEM a_s_rctl[] = { KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM a_d_ralt[] = { KC_A, KC_D, COMBO_END};
const uint16_t PROGMEM a_f_lctlralt[] = { KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM a_g_esc[] = { KC_A, KC_G, COMBO_END};
const uint16_t PROGMEM j_k_rctl[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM j_l_ralt[] = { KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM j_scln_lctlralt[] = { KC_J, KC_SCLN, COMBO_END};
const uint16_t PROGMEM a_q_esc[] = { KC_A, KC_Q, COMBO_END};
const uint16_t PROGMEM e_i_ins[] = { KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM s_i_rsftins[] = { KC_S, KC_I, COMBO_END};
const uint16_t PROGMEM c_t_lctlf5[] = { KC_C, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [A_S_RCTL] = COMBO(a_s_rctl, KC_RCTL),
  [A_D_RALT] = COMBO(a_d_ralt, KC_RALT),
  [A_F_LCTLRALT] = COMBO(a_f_lctlralt, LCTL(KC_RALT)),
  [A_G_ESC] = COMBO(a_g_esc, KC_ESC),
  [J_K_RCTL] = COMBO(j_k_rctl, KC_RCTL),
  [J_L_RALT] = COMBO(j_l_ralt, KC_RALT),
  [J_SCLN_LCTLRALT] = COMBO(j_scln_lctlralt, LCTL(KC_RALT)),
  [A_Q_ESC] = COMBO(a_q_esc, KC_ESC),
  [E_I_INS] = COMBO(e_i_ins, KC_INS),
  [S_I_RSFTINS] = COMBO(s_i_rsftins, RSFT(KC_INS)),
  [C_T_LCTLF5] = COMBO(c_t_lctlf5, LCTL(KC_F5)),
  
};
*/
