// data types and functions to read keyswitch matrix
#pragma once
#include <Arduino.h>
#include <array>

const uint8_t cols{5},rows{4},caps{9};
using std::array;

const array<uint8_t,caps>tnsy_cap_pins{0,1,15,16,17,18,19,22,23};
const array<uint8_t,cols>tnsy_col_pins{2,5,6,7,8};
const array<uint8_t,rows>tnsy_row_pins{10,11,12,14};

typedef array<int,caps> CapsRaw; // Raw touchRead value
typedef array<bool,caps> CapsTouched; // Was cap threshold exceeded?

// MechLayer is 2D array of printable characters, mapped to a switch matrix.
typedef const array<array<int,cols>,rows> MechLayer; // ASCII (0-127) and MODIFIERKEY_FOO (57345+)
typedef array<array<bool,cols>,rows> MechsPressed; // bitvector to select ASCII chars from MechLayer

void setup_matrix(void){
    for(const auto &i : tnsy_col_pins) pinMode(tnsy_col_pins[i],INPUT_PULLUP);
    for(const auto &i : tnsy_row_pins) pinMode(tnsy_row_pins[i],OUTPUT_OPENDRAIN);
}

void read_mech(MechsPressed &mp){
    // Switch Matrix:
    //
    //  row0 ------+---------+   Diodes with cathodes pointing up are shown as (A).
    //             |         |   Switches are shown as backslashes.
    //             |         |   Columns are inputs with pullups.
    //            \         \    Rows are open-drain outputs.
    //             |         |
    //            (A)       (A)
    //             |         |
    //             |         |   Scan:
    //             |         |      row0 low, read col1, read col2.
    //  row1 --+---------+   |      row0 hiZ.
    //         |   |     |   |      row1 low, read col1, read col2.
    //         |   |     |   |      row1 hiZ.
    //        \    |    \    |
    //         |   |     |   |   Diodes prevent ghosting, allow NKRO.
    //        (A)  |    (A)  |
    //         |   |     |   |
    //         +---+     +---+
    //             |         |
    //             |         |
    //             col0      col1
    for(uint8_t row=0,N=mp.size(); row<N; ++row){
        digitalWrite(tnsy_row_pins[row],LOW);
        for(uint8_t col=0, M=mp[row].size(); col<M; ++col)
            mp[row][col] = digitalRead(tnsy_col_pins[col]);
        digitalWrite(tnsy_col_pins[row],HIGH);
    }
}

void read_caps_raw(CapsRaw &cr){
    for(const auto &touch_pin : cr)
        cr[touch_pin] = touchRead(tnsy_cap_pins[touch_pin]);
}

void read_caps(const CapsRaw &cr, CapsTouched ct){
    // TODO determine if a more sophisticated threshold is needed
    for(const auto &touch_pin : cr)
        ct[touch_pin] = 1000<cr[touch_pin];
}
