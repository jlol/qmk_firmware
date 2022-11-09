/* Copyright 2018 Jack Humbert
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


#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LAYER0] = LAYOUT(
	KC_P7, KC_P8, KC_P9,
       	KC_P4, KC_P5, KC_P6,
       	KC_P1, KC_P2, KC_P3,
       	LT(2,KC_PCMM), KC_P0, LT(1,KC_PDOT)),

[_LAYER1] = LAYOUT(
	TO(3), TO(4), KC_PGUP, 
	KC_NO, KC_NO, KC_PGDN,
       	KC_NO, KC_NO, KC_ENT,
       	KC_TRNS, KC_NO, KC_TRNS),

[_LAYER2] = LAYOUT(
	KC_PSLS, KC_PAST, KC_PMNS,
       	KC_NO, KC_NO, KC_PPLS,
       	KC_DQUO, KC_QUOT, KC_PCMM,
       	KC_TRNS, KC_NO, KC_PEQL),

[_LAYER3] = LAYOUT(
	TO(0), KC_CALC, KC_PSCR,
       	KC_MUTE, KC_VOLD, KC_VOLU,
       	KC_PGDN, KC_UP, KC_PGUP,
       	KC_LEFT, KC_DOWN, KC_RGHT),

[_LAYER4] = LAYOUT(
	TO(0), KC_PSCR, KC_SLEP,
       	KC_WH_U, KC_BTN3, KC_WH_D,
       	KC_BTN1, KC_MS_U, KC_BTN2,
       	KC_MS_L, KC_MS_D, KC_MS_R) 

};
