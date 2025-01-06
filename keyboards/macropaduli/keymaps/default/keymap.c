// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "analog.h"
#include "qmk_midi.h"

#define POT_TOLERANCE 12

extern MidiDevice midi_device;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │10 │11 │12 │   │
     * ├───┼───┼───┼───│
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤
     * │ 3 │ 4 │ 6 │   │
     * ├───┴───┼───┼───│
     * │ 1 │ 2 │ 3 │   │
     * └───┴───┴───┴───┘
     */
    [0] = //LAYOUT_numpad_12x1(
    {{
        KC_P7,   KC_A,   KC_P9,
        KC_B, KC_C,   KC_D,
        KC_F,   KC_E,   KC_G,
        KC_P3,   KC_PENT, KC_H
}}
    //)
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
};

uint8_t divisor = 0;
int16_t pot_oldVal_A = 0;
int16_t pot_val_A    = 0;
int16_t pot_ccVal_A  = 0;

int16_t pot_oldVal_B = 0;
int16_t pot_val_B    = 0;
int16_t pot_ccVal_B  = 0;

//enum midi_cc_keycodes_LTRM { MIDI_CC1 = SAFE_RANGE, ... MIDI_CC24}

void slider(void) {
    if (divisor++) { // only run the slider function 1/256 times it's called
        return;
    }

    pot_val_A = (analogReadPin(SLIDER_PINA));
    pot_val_B = (analogReadPin(SLIDER_PINB));


    if (abs(pot_val_A - pot_oldVal_A) > POT_TOLERANCE) {
        pot_ccVal_A = pot_val_A / 8;
        pot_oldVal_A = pot_val_A;
        //midi_send_cc(&midi_device, 1, 20, pot_ccVal);
        //midi_send_cc(&midi_device, 2, 0x30, 0x7F - (analogReadPin(SLIDER_PINA) >> 1));
        midi_send_cc(&midi_device, 2, 0x30, pot_ccVal_A);
    }

    if (abs(pot_val_B - pot_oldVal_B) > POT_TOLERANCE) {
        pot_ccVal_B = pot_val_B / 8;
        pot_oldVal_B = pot_val_B;
        //midi_send_cc(&midi_device, 1, 21, pot_ccVal);
        //midi_send_cc(&midi_device, 2, 0x31, 0x7F - (analogReadPin(SLIDER_PINB) >> 2));
        midi_send_cc(&midi_device, 2, 0x31, pot_ccVal_B);
    }
}

void matrix_init_user(void) {
    analogReference(ADC_REF_POWER);

    pot_val_A = pot_oldVal_A = (analogReadPin(SLIDER_PINA));
    pot_ccVal_A = pot_val_A / 8;

    pot_val_B = pot_oldVal_B = (analogReadPin(SLIDER_PINB));
    pot_ccVal_B = pot_val_B / 8;
}

void matrix_scan_user(void) {
    slider();
}
