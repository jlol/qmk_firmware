/* Copyright 2021 Harshit Goel
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

#include "pteron36.h"

//common encoder setup

bool encoder_update_kb(uint8_t index, bool clockwise) {
    //if (!encoder_update_user(index, clockwise)) { return false; }

    if (index == 0) { // First encoder 
        if (clockwise) {
<<<<<<< HEAD
<<<<<<< HEAD
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
=======
<<<<<<< HEAD
=======
>>>>>>> 8f6d320382 (Combos)
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
<<<<<<< HEAD
>>>>>>> 4fc55134ec (layer changes)
>>>>>>> 0adca45d00 (layer changes)
=======
>>>>>>> 8f6d320382 (Combos)
        }
    }

    return true;
}

//common oled support.
#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    if (!oled_task_user()) {
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
