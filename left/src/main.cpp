// m20c9 left side -- https://github.com/hoosierEE/m20c9
#include <Arduino.h>
#include <m20c9.hpp>

// Left side mechanical keys
MechLayer Ldefault{{
        {'1', '2', '3', '4', '5'},
        {'q', 'w', 'e', 'r', 't'},
        {'a', 's', 'd', 'f', 'g'},
        {'z', 'x', 'c', 'v', 'b'}}};

MechLayer Lshifted{{
        {'!', '@', '#', '$', '%'},
        {'Q', 'W', 'E', 'R', 'T'},
        {'A', 'S', 'D', 'F', 'G'},
        {'Z', 'X', 'C', 'V', 'B'}}};

MechLayer Lsymbols{{
        {' ', ' ', ' ', ' ', ' '},
        {'@', '#', '$', '%', '['},
        {' ', '-', '+', '=', '('},
        {'_', '~', '`', '!', '{'}}};

// HID keyboard is rate limited to 1ms.
const uint32_t rate{10};// 10ms
elapsedMillis t;


void setup(){
}

void loop(){
}
