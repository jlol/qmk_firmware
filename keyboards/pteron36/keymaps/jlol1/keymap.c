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

enum custom_keycodes {
    BASE = SAFE_RANGE,
    MOVE,
    NUMB,
    NUMPAD,
    SYMB,
//    FNUM
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x5_3_encoder(
	KC_Q, LGUI_T(KC_W), KC_E, KC_R, KC_T, 						KC_Y, KC_U, KC_I, KC_O, KC_P, 
	LCTL_T(KC_A), LALT_T(KC_S), KC_D, KC_F, KC_G, 				KC_H, KC_J, KC_K, LALT_T(KC_L), TD(TD_SCLN_QUOT), 
	LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_AUDIO_MUTE, 			KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), 
	KC_LEAD, LT(_MOVE, KC_BSPC), LT(_SYMB, KC_ENT), TO(_MOVE),		TO(_NUMB), MO(_SYMB), KC_SPC, LT(_NUMB,KC_DEL)
),

[_MOVE] = LAYOUT_split_3x5_3_encoder(
	KC_ESC, LGUI(KC_TAB), SGUI(KC_S), LALT(KC_F4), LSFT(KC_INS), 		KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSPC,
	KC_TAB, KC_CUT, KC_COPY, KC_PSTE, KC_FIND,	 			KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
	KC_LSFT, KC_PSCR, KC_NO, KC_NO, TO(_NUMPAD), KC_AUDIO_MUTE,	 	LSA(KC_N), KC_NO, KC_CAPS, KC_NUM, KC_INS,
	KC_TRNS, KC_TRNS, KC_TRNS, TO(0), 					TO(0), KC_LCTL, KC_TRNS, KC_NO 
),

[_NUMB] = LAYOUT_split_3x5_3_encoder(
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 				KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
	KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_AUDIO_MUTE, 	KC_INS, KC_NO, KC_COMM, KC_DOT, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, TO(0),				TO(0), KC_TRNS, KC_RCTL, KC_RALT
),

[_NUMPAD] = LAYOUT_split_3x5_3_encoder(
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PMNS, KC_7, KC_8, KC_9, KC_PPLS,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PAST, KC_4, KC_5, KC_6, KC_PDOT,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_AUDIO_MUTE,		KC_PSLS, KC_1, KC_2, KC_3, KC_PEQL,
	KC_NO, KC_BSPC, KC_ENT, TO(0), 					TO(0), KC_LGUI, KC_SPC, KC_0
),

[_SYMB] = LAYOUT_split_3x5_3_encoder(
	KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, 			KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC,
	KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, 			KC_UNDS, KC_PLUS, KC_MINS, KC_EQL, KC_DQUO,
	KC_TILD, KC_GRV, KC_NO, KC_NO, KC_NO, KC_AUDIO_MUTE, 		KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS,
	KC_TRNS, KC_NO, KC_TRNS, KC_NO, 				KC_NO, KC_NO, KC_NO, KC_NO
),
/*
[_FNUM] = LAYOUT_split_3x5_3_encoder(
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC,
	KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AUDIO_MUTE,		KC_NO, KC_NO, KC_COMM, KC_DOT, KC_NO,
	KC_RCTL, KC_TRNS, KC_TRNS, TO(0),				TO(0), KC_TRNS, KC_SPC, KC_RALT
)
	*/
};

enum combos {
  //AS_CTRL,
  //LSCLN_CTRL,
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
  //[UI_ALT] = COMBO(ui_combo, TO(_NUMPAD)),
  //[PO_CTRL] = COMBO(po_combo, KC_LCTL),
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    return true;
};
*/

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

