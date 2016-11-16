// m20c9 left side -- https://github.com/hoosierEE/m20c9
#include <Arduino.h>
#include <m20c9.hpp>
#include "keymap.hpp"

const uint32_t rate{10};// 10ms
elapsedMillis t;

void setup(){
    Serial.println(MLsymbols[0][0]);
}

void loop(){
}
