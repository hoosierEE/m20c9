#include <Arduino.h>
#include "readers.hpp"
#include "keymap.hpp"

CapsRaw cr;
CapsTouched ct;
MechsPressed mp;

void setup(){
    for(const auto&i : tnsy_col_pins) pinMode(i,INPUT_PULLUP);
    for(const auto&i : tnsy_row_pins) pinMode(i,OUTPUT_OPENDRAIN);
}

void loop(){

    // Read mechanical switches
    for(uint8_t row=0; row<rows; ++row){
        digitalWrite(tnsy_row_pins[row],LOW);
        for(uint8_t col=0; col<cols; ++col){
            mp[row][col] = digitalRead(tnsy_col_pins[col]);
        }
        digitalWrite(tnsy_row_pins[row],HIGH);
    }

    // Read capacitive pads
    for(uint8_t i=0;i<caps;++i){
        cr[i] = touchRead(tnsy_cap_pins[i]);
        // TODO determine if a more sophisticated threshold is needed
        ct[i] = 1000 < cr[i];
    }

}
