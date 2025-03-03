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
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 39687ddc2f (v2)
//#define _FNUM 5


////////////////////////////////////////////////////////////////////////////////////
// https://docs.qmk.fm/#/feature_tap_dance?id=example-4-39quad-function-tap-dance39
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    TD_SCLN_QUOT,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);
////////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
=======
#define _FNUM 5
>>>>>>> f6c77ec26f (new layer for numbers)
=======
>>>>>>> 39687ddc2f (v2)

enum custom_keycodes {
    BASE = SAFE_RANGE,
    MOVE,
    NUMB,
    NUMPAD,
    SYMB,
<<<<<<< HEAD
<<<<<<< HEAD
//    FNUM
=======
    FNUM
>>>>>>> f6c77ec26f (new layer for numbers)
=======
//    FNUM
>>>>>>> 39687ddc2f (v2)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x5_3_encoder(
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	KC_Q, LGUI_T(KC_W), KC_E, KC_R, KC_T, 						KC_Y, KC_U, KC_I, KC_O, KC_P, 
	LCTL_T(KC_A), LALT_T(KC_S), KC_D, KC_F, KC_G, 				KC_H, KC_J, KC_K, LALT_T(KC_L), TD(TD_SCLN_QUOT), 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_AUDIO_MUTE, 			KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
	KC_LEAD, LT(_MOVE, KC_BSPC), LT(_SYMB, KC_ENT), TO(_MOVE),		TO(_NUMB), MO(_SYMB), KC_SPC, LT(_NUMB,KC_DEL)
=======
	KC_Q, KC_W, KC_E, KC_R, KC_T, 				KC_Y, KC_U, KC_I, KC_O, KC_P, 
	KC_A, KC_S, KC_D, KC_F, KC_G, 				KC_H, KC_J, KC_K, KC_L, TD(TD_SCLN_QUOT), 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_AUDIO_MUTE, 	KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
<<<<<<< HEAD
<<<<<<< HEAD
	KC_LALT, MO(1), MO(4), TO(1), 				TO(2), LT(4,KC_LGUI), KC_SPC, LT(2,KC_DEL)
>>>>>>> 0adca45d00 (layer changes)
=======
	KC_LALT, LT(1, KC_BSPC), MO(4), TO(1), 				TO(2), LT(4,KC_LGUI), KC_SPC, LT(2,KC_DEL)
>>>>>>> db1e1f46e7 (restored backspace in thumb)
=======
	KC_LALT, LT(1, KC_BSPC), LT(4, KC_ENT), TO(1),		TO(5), LT(4,KC_LGUI), KC_SPC, LT(2,KC_DEL)
>>>>>>> f6c77ec26f (new layer for numbers)
=======
	KC_Q, KC_W, KC_E, KC_R, KC_T, 						KC_Y, KC_U, KC_I, KC_O, KC_P, 
	LCTL_T(KC_A), LALT_T(KC_S), KC_D, KC_F, KC_G, 				KC_H, KC_J, KC_K, LALT_T(KC_L), TD(TD_SCLN_QUOT), 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_AUDIO_MUTE, 			KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
	KC_LALT, LT(_MOVE, KC_BSPC), LT(_SYMB, KC_ENT), TO(_MOVE),		TO(_NUMB), LT(_SYMB,KC_LGUI), KC_SPC, LT(_NUMB,KC_DEL)
>>>>>>> 39687ddc2f (v2)
=======
	KC_Q, LGUI_T(KC_W), KC_E, KC_R, KC_T, 						KC_Y, KC_U, KC_I, KC_O, KC_P, 
	LCTL_T(KC_A), LALT_T(KC_S), KC_D, KC_F, KC_G, 				KC_H, KC_J, KC_K, LALT_T(KC_L), TD(TD_SCLN_QUOT), 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_AUDIO_MUTE, 			KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
	KC_LEAD, LT(_MOVE, KC_BSPC), LT(_SYMB, KC_ENT), TO(_MOVE),		TO(_NUMB), MO(_SYMB), KC_SPC, LT(_NUMB,KC_DEL)
>>>>>>> 6c2cd42cf8 (Added leader key, removed app key from right thumb, added futurama images in oled :))
=======
	KC_Q, KC_W, KC_E, KC_R, KC_T, 						KC_Y, KC_U, KC_I, KC_O, KC_P, 
	LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G, 				        KC_H, KC_J, KC_K, KC_L, TD(TD_SCLN_QUOT), 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_AUDIO_MUTE, 			KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
	KC_LALT, LT(_MOVE, KC_BSPC), MO(_NUMB), KC_ENT,				KC_LCTL, MO(_SYMB), KC_SPC, LT(_NUMB,KC_DEL)
>>>>>>> 82ba9c28a0 (Added uli)
),

[_MOVE] = LAYOUT_split_3x5_3_encoder(
	KC_ESC, LGUI(KC_TAB), SGUI(KC_S), LALT(KC_F4), LSFT(KC_INS), 		KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSPC,
	KC_TAB, KC_CUT, KC_COPY, KC_PSTE, KC_FIND,	 			KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	KC_LSFT, KC_PSCR, KC_NO, KC_NO, TO(_NUMPAD), KC_AUDIO_MUTE,	 	LSA(KC_N), KC_NO, KC_CAPS, KC_NUM, KC_INS,
<<<<<<< HEAD
=======
	KC_PSCR, KC_NO, KC_NO, KC_NO, TO(3), KC_AUDIO_MUTE,	 		LSA(KC_N), KC_NO, KC_CAPS, KC_NUM, KC_INS,
>>>>>>> 0adca45d00 (layer changes)
=======
	KC_LSFT, KC_PSCR, KC_NO, KC_NO, TO(3), KC_AUDIO_MUTE,	 		LSA(KC_N), KC_NO, KC_CAPS, KC_NUM, KC_INS,
>>>>>>> 3f4ab4c451 (added shift to move tab)
=======
	KC_LSFT, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_AUDIO_MUTE,	 		LSA(KC_N), KC_NO, KC_CAPS, KC_NUM, KC_INS,
>>>>>>> 39687ddc2f (v2)
=======
	KC_LSFT, KC_PSCR, KC_NO, KC_NO, TO(_NUMPAD), KC_AUDIO_MUTE,	 	LSA(KC_N), KC_NO, KC_CAPS, KC_NUM, KC_INS,
>>>>>>> 6c2cd42cf8 (Added leader key, removed app key from right thumb, added futurama images in oled :))
	KC_TRNS, KC_TRNS, KC_TRNS, TO(0), 					TO(0), KC_LCTL, KC_TRNS, KC_NO 
=======
	KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT,				KC_LCTL, KC_LCTL, KC_TRNS, KC_NO 
>>>>>>> 82ba9c28a0 (Added uli)
),

[_NUMB] = LAYOUT_split_3x5_3_encoder(
<<<<<<< HEAD
<<<<<<< HEAD
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 				KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
	KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_AUDIO_MUTE, 	KC_INS, KC_NO, KC_COMM, KC_DOT, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS,  KC_ENT,				KC_LCTL, KC_TRNS, KC_RCTL, KC_RALT
),

[_NUMPAD] = LAYOUT_split_3x5_3_encoder(
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PMNS, KC_7, KC_8, KC_9, KC_PPLS,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PAST, KC_4, KC_5, KC_6, KC_PDOT,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_AUDIO_MUTE,		KC_PSLS, KC_1, KC_2, KC_3, KC_PEQL,
	KC_NO, KC_BSPC, KC_ENT, TO(0), 					TO(0), KC_LGUI, KC_SPC, KC_0
=======
	KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0,
=======
>>>>>>> 39687ddc2f (v2)
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 				KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
	KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_AUDIO_MUTE, 	KC_INS, KC_NO, KC_COMM, KC_DOT, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, TO(0),				TO(0), KC_TRNS, KC_RCTL, KC_RALT
),

[_NUMPAD] = LAYOUT_split_3x5_3_encoder(
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PMNS, KC_7, KC_8, KC_9, KC_PPLS,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PAST, KC_4, KC_5, KC_6, KC_PDOT,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_AUDIO_MUTE,		KC_PSLS, KC_1, KC_2, KC_3, KC_PEQL,
<<<<<<< HEAD
	KC_NO, KC_BSPC, KC_ENT, KC_NO, 					KC_NO, KC_NO, KC_NO, KC_0
>>>>>>> 0adca45d00 (layer changes)
=======
	KC_NO, KC_BSPC, KC_ENT, TO(0), 					TO(0), KC_LGUI, KC_SPC, KC_0
>>>>>>> 39687ddc2f (v2)
),

[_SYMB] = LAYOUT_split_3x5_3_encoder(
	KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, 			KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC,
	KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, 			KC_UNDS, KC_PLUS, KC_MINS, KC_EQL, KC_DQUO,
	KC_TILD, KC_GRV, KC_NO, KC_NO, KC_NO, KC_AUDIO_MUTE, 		KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS,
	KC_TRNS, KC_NO, KC_TRNS, KC_LALT,				KC_LCTL, KC_NO, KC_NO, KC_NO
),
<<<<<<< HEAD
<<<<<<< HEAD
/*
=======

>>>>>>> f6c77ec26f (new layer for numbers)
=======
/*
>>>>>>> 39687ddc2f (v2)
[_FNUM] = LAYOUT_split_3x5_3_encoder(
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC,
	KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AUDIO_MUTE,		KC_NO, KC_NO, KC_COMM, KC_DOT, KC_NO,
	KC_RCTL, KC_TRNS, KC_TRNS, TO(0),				TO(0), KC_TRNS, KC_SPC, KC_RALT
)
<<<<<<< HEAD
<<<<<<< HEAD
	*/
=======
>>>>>>> f6c77ec26f (new layer for numbers)
};

enum combos {
<<<<<<< HEAD
  //AS_CTRL,
  //LSCLN_CTRL,
  JK_ESC,
  //KL_ALT,
  HJ_TAB,
  QW_TAB,
  MCOMMA_NUM,
  XC_GUI
  //UI_ALT
//  PO_CTRL,
};

//const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
//const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};
//const uint16_t PROGMEM lscln_combo[] = {KC_L, TD(TD_SCLN_QUOT), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
//const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM xc_gui[] = {KC_C, KC_X, COMBO_END};
//const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
//const uint16_t PROGMEM po_combo[] = {KC_P, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
//  [AB_ESC] = COMBO(ab_combo, KC_ESC),
  //[AS_CTRL] = COMBO(as_combo, KC_LCTL),
  //[LSCLN_CTRL] = COMBO(lscln_combo, KC_LCTL),
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  //[KL_ALT] = COMBO(kl_combo, KC_LALT),
  [HJ_TAB] = COMBO(hj_combo, KC_TAB),
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
  [MCOMMA_NUM] = COMBO(mcomma_combo, OSL(2)),
  [XC_GUI] = COMBO(xc_gui, KC_LGUI)
  //[UI_ALT] = COMBO(ui_combo, TO(_NUMPAD)),
  //[PO_CTRL] = COMBO(po_combo, KC_LCTL),
=======
  AS_CTRL,
  LSCLN_CTRL,
=======
	*/
};

enum combos {
  //AS_CTRL,
  //LSCLN_CTRL,
>>>>>>> 39687ddc2f (v2)
  JK_ESC,
  //KL_ALT,
  HJ_TAB,
  QW_TAB,
  MCOMMA_NUM,
  //UI_ALT
//  PO_CTRL,
};

//const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
//const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};
//const uint16_t PROGMEM lscln_combo[] = {KC_L, TD(TD_SCLN_QUOT), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
//const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
//const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
//const uint16_t PROGMEM po_combo[] = {KC_P, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
//  [AB_ESC] = COMBO(ab_combo, KC_ESC),
  //[AS_CTRL] = COMBO(as_combo, KC_LCTL),
  //[LSCLN_CTRL] = COMBO(lscln_combo, KC_LCTL),
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  //[KL_ALT] = COMBO(kl_combo, KC_LALT),
  [HJ_TAB] = COMBO(hj_combo, KC_TAB),
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
  [MCOMMA_NUM] = COMBO(mcomma_combo, OSL(2)),
<<<<<<< HEAD
<<<<<<< HEAD
  //[UI_ALT] = COMBO(ui_combo, KC_LALT),
>>>>>>> 8f6d320382 (Combos)
=======
  [UI_ALT] = COMBO(ui_combo, TO(_NUMPAD)),
=======
  //[UI_ALT] = COMBO(ui_combo, TO(_NUMPAD)),
>>>>>>> 6c2cd42cf8 (Added leader key, removed app key from right thumb, added futurama images in oled :))
  //[PO_CTRL] = COMBO(po_combo, KC_LCTL),
>>>>>>> 39687ddc2f (v2)
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


/*
bool handle_mod(uint16_t keycode, uint16_t mod, uint16_t tap, keyrecord_t *record)
{
    if (record->tap.count > 0) {    // Key is being tapped.
	if (record->event.pressed) {
	    // Handle tap press event...
	} else {
	    // Handle tap release event...
	}
	
    } else {                        // Key is being held.
	if (record->event.pressed) {
	    // Handle hold press event...
	} else {
	    // Handle hold release event...
	}
    }
    return true;
}
*/

static uint16_t idle_timer = 0;
static bool led_on = true;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
    switch (keycode) { 
    case LALT_T(KC_D):
	return handle_mod(keycode, KC_LALT, KC_D, record);
    case LALT_T(KC_K):
	return handle_mod(keycode, KC_LALT, KC_K, record);
    case LCTL_T(KC_F):
	return handle_mod(keycode, KC_LCTL, KC_F, record);
    case LCTL_T(KC_J):
	return handle_mod(keycode, KC_LCTL, KC_J, record);
    }

*/
	if (record->event.pressed) {
		switch (keycode) {
			    case KC_A ... KC_SLASH:  // These keys type letters, digits, symbols.
				    if (!led_on) {
					    led_on = true;
					    oled_on();
				    }

				    idle_timer = timer_read();

				    break;
		}
	}
    return true;
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	case LSFT_T(KC_Z):
	case RSFT_T(KC_SLSH):
		// Immediately select the hold action when another key is pressed.
		return true;
	default:
		// Do not select the hold action when another key is pressed.
		return false;
	}
}	


// https://docs.qmk.fm/#/feature_tap_dance?id=example-4-39quad-function-tap-dance39

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SCLN); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_QUOT); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        default: break;
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SCLN); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_QUOT); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        //case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)

    //[TD_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 6c2cd42cf8 (Added leader key, removed app key from right thumb, added futurama images in oled :))


// LEADER
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Create file in current directory
    SEQ_TWO_KEYS(KC_F, KC_N) {
      register_code(KC_LSFT);
      register_code(KC_LALT);
      register_code(KC_N);
      unregister_code(KC_N);
      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
    }

    // Search everywhere
    SEQ_TWO_KEYS(KC_S, KC_E) {
      register_code(KC_LCTL);
      register_code(KC_T);
      unregister_code(KC_T);
      unregister_code(KC_LCTL);   
    }

    // Find in solution
    SEQ_TWO_KEYS(KC_F, KC_E) {
      register_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_F);
      unregister_code(KC_F);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
    }

    // Refactor this
    SEQ_TWO_KEYS(KC_C, KC_R) {
      register_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);    
    }

    // Extract method
    SEQ_TWO_KEYS(KC_C, KC_E) {
      register_code(KC_LCTL);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_LCTL);    
      register_code(KC_M);
      unregister_code(KC_M);
    }

    // Introduce variable
    SEQ_THREE_KEYS(KC_C, KC_I, KC_V) {
      register_code(KC_LCTL);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_LCTL);    
      register_code(KC_V);
      unregister_code(KC_V);
    }

    // Introduce variable
    SEQ_THREE_KEYS(KC_C, KC_I, KC_F) {
      register_code(KC_LCTL);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_LCTL);    
      register_code(KC_F);
      unregister_code(KC_F);
    }

    // Introduce variable
    SEQ_THREE_KEYS(KC_C, KC_I, KC_P) {
      register_code(KC_LCTL);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_LCTL);    
      register_code(KC_P);
      unregister_code(KC_P);
    }
  }
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 39687ddc2f (v2)
=======
>>>>>>> 6c2cd42cf8 (Added leader key, removed app key from right thumb, added futurama images in oled :))
=======
//common oled support.
#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }

    if (led_on && timer_elapsed(idle_timer) > 15000)
    {
	    led_on = false;
	    oled_off();
    }

    if (!led_on)
    {
	    return false;
    }


    if (is_keyboard_master()) {

        static const char PROGMEM pexpress_logo[] = {
		// 'planetexp_oled', 128x32px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
		0xc0, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 
		0xc1, 0xc3, 0xc7, 0x0c, 0x5d, 0x7c, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7e, 0x7c, 0x7c, 
		0x7c, 0x7c, 0x74, 0x74, 0x6c, 0x7c, 0x7c, 0x74, 0x6c, 0x7c, 0x7d, 0x7d, 0x75, 0x6c, 0x7c, 0x7c, 
		0x7c, 0x74, 0x6c, 0x78, 0x70, 0x70, 0x70, 0x70, 0x70, 0x60, 0x60, 0x60, 0x40, 0x80, 0x80, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 
		0x07, 0x07, 0x03, 0x00, 0x00, 0x02, 0x0e, 0x0e, 0xce, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
		0x7e, 0x7e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x1e, 
		0x1e, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x08, 0x0c, 0x0e, 0x0f, 0x0f, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	oled_write_raw_P(pexpress_logo, sizeof(pexpress_logo));

        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_ln_P(PSTR("Base"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR("Move"), false);
                break;
            case 2:
                oled_write_ln_P(PSTR("Numbers"), false);
                break;
            case 3:
                oled_write_ln_P(PSTR("NumPad"), false);
            case 4:
                oled_write_ln_P(PSTR("Symbols"), false);
                break;
            //case 5:
            //    oled_write_ln_P(PSTR("Only numbers"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
         }

    } else {
        static const char PROGMEM qmk_logo[] = {
		// 'bender_oled', 128x32px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 
		0x02, 0x02, 0x02, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 
		0x07, 0x07, 0xc7, 0xe6, 0x04, 0xf4, 0xf4, 0xf4, 0xe4, 0x04, 0x04, 0x03, 0xfc, 0xfe, 0xe7, 0xf3, 
		0xf3, 0xf9, 0xf9, 0xf9, 0xf1, 0xf3, 0xe3, 0xff, 0xfe, 0xf9, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 
		0x04, 0x00, 0x00, 0x08, 0x08, 0x10, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xc0, 0xde, 0xde, 0xde, 0x00, 0xde, 0xde, 0xde, 0xde, 0x00, 0x00, 0x00, 0xff, 0xff, 0x3f, 0x7f, 
		0x7f, 0x78, 0xf8, 0x78, 0x7f, 0x7f, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x38, 0x40, 0x40, 0x40, 0x40, 
		0x40, 0x40, 0x00, 0x00, 0x40, 0x20, 0x10, 0x10, 0x00, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x03, 0x7b, 0x7b, 0x7b, 0x00, 0x7b, 0x7b, 0x7b, 0x7b, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfc, 0xfe, 
		0xfe, 0x1e, 0x1e, 0x1e, 0xfe, 0xfe, 0xfc, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0c, 0x02, 0x02, 0x02, 0x02, 
		0x02, 0x02, 0x00, 0x00, 0x02, 0x04, 0x08, 0x08, 0x00, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
		0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2c, 0x7e, 0x52, 0x5e, 0x44, 0x40, 0x40, 0x40, 0x40, 0x40, 
		0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x20, 0x20, 
		0x00, 0x20, 0x23, 0x27, 0x20, 0x2f, 0x2f, 0x2f, 0x27, 0x20, 0x20, 0xc0, 0x3f, 0x7f, 0xe7, 0xcf, 
		0xcf, 0x9f, 0x9f, 0x9f, 0x8f, 0xcf, 0xc7, 0xff, 0x7f, 0x9f, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 
		0x20, 0x00, 0x00, 0x10, 0x10, 0x08, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
		
	oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
        //oled_write_P(qmk_logo, false);
       // oled_scroll_left();  // Turns on scrolling
    }
    return false;
}
#endif
>>>>>>> 82ba9c28a0 (Added uli)
