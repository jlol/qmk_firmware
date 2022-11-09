#include QMK_KEYBOARD_H
#include "snowe.h"

/*
enum unicode_names {
    ENYE,
    SENYE
};

const uint32_t PROGMEM unicode_map[] = {
    [ENYE]  = 0x00F1,
    [SENYE] = 0x00D1
};
*/
/*
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NUMBERS,
  _SYMB2,
  _GAME
};
*/

enum custom_keycodes {
    SELWORD = SAFE_RANGE,
    SELLINE
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT(
	QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, 					KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, 
	KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, 					KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, 
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, 		KC_RBRC,KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
			   KC_LGUI, KC_LALT, LT(1, KC_SPC), MO(4),        MO(2), KC_SPC, KC_DEL, MO(3)),

[_LOWER] = LAYOUT(
	KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 				KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
	KC_TRNS, KC_NO, SELWORD, SELLINE, KC_NO, KC_CAPS,                       KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 			 	KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 	        KC_TRNS, TO(3), KC_TRNS, KC_TRNS),

[_RAISE] = LAYOUT(
	KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 				KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
	KC_TRNS, KC_CUT, KC_COPY, KC_PSTE, RSFT(KC_INS), KC_FIND, 		KC_NO, KC_PLUS, KC_PMNS, KC_EQL, KC_NO, KC_NO,
        KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, 		KC_BSLS, KC_LT, KC_GT, KC_LBRC, KC_RBRC, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
				KC_TRNS, KC_TRNS, TO(5), KC_TRNS, 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_NUMBERS] = LAYOUT(
	TO(0), KC_NO, KC_NO, KC_NO, KC_NO, TO(5), 				KC_PAST, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_BSPC, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 				KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_TRNS, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 			        KC_NO,  KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, 
	KC_TRNS, KC_PSCR, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, 	KC_NUM,  KC_NO, KC_PCMM, KC_P0, KC_PDOT, KC_PENT, KC_TRNS, 
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_SYMB2] = LAYOUT(
	TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 					KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 					KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 					KC_NO, KC_DQUO, KC_QUOT, KC_MINS, KC_UNDS, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), 	             TO(5),KC_NO, KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, 
			KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO),

[_GAME] = LAYOUT(
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, 					KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
	KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, 					KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, 
	KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, 					KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, 
	KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, TO(0), 	             TO(0),KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
			KC_LALT, KC_SPC, KC_SPC, KC_U,       KC_BSLS, KC_TRNS, KC_TRNS, KC_RALT) 

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return state;
  //return update_tri_layer_state(state, _LOWER, _RAISE, _SYMB2);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
/*
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    oled_task_user_render();
    return false;
}
*/
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    	case SELWORD:  // Selects the current word under the cursor.
	    if (record->event.pressed) {
		SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
	    }
	break;
	case SELLINE:  // Selects the current line.
	  if (record->event.pressed) {
	    SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
	  }
	  break;
        /*case QMENYE:
            if (record->event.pressed) {
                uint8_t shift = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                if (shift) {
                    //SEND_STRING("Ñ");

                } else {
                    SEND_STRING("ñ");
                }
            }
            break;
	    */


#ifdef LUNA_ENABLE
            /* KEYBOARD PET STATUS START */

        case KC_LCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        case KC_TAB:
            if (record->event.pressed) {
                isBarking = true;
            } else {
                isBarking = false;
            }
            break;
 
        /* KEYBOARD PET STATUS END */

#endif
 
    }
   
    //if (record->event.pressed) {
#ifdef OLED_ENABLE
    //set_keylog(keycode, record);
#endif
    // set_timelog();
    //}
  return true;
}
