/**
   m30c10 keyboard firmware for Teensy 3.1
   https://github.com/hoosierEE/m30c10
*/
#include <Arduino.h>
#include <Cherry.h>
#include <CapSwitch.h>

const uint32_t MS_OUT{10};  // output timer (milliseconds)
elapsedMillis t;
//static const uint8_t MECH_SWITCH_COUNT{30};  // # mechanical switches
//static const uint8_t CAP_SWITCH_COUNT{10};  // # capacitive switches
Cherry mechswitch;
CapSwitch capswitch(22);

void setup() {
    Serial.begin(9600);
}

void loop() {
    capswitch.update();
    mechswitch.update();
    if (t >= MS_OUT) {
        t -= MS_OUT;
        capswitch.pressed();
        mechswitch.render();
    }
}
