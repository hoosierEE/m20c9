#include <Arduino.h>
#include "m20c9.hpp"
#include "keymap.hpp"

CapsRaw cr;
CapsTouched ct;
MechsPressed mp;

void setup(){
    setup_matrix();
}

void loop(){
    read_mech(mp);
    read_caps_raw(cr);
    read_caps(ct,cr);
}
