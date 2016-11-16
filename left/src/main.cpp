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

// Both: scan own switches, send/receive messages from other half.
// 1 half: commuincate with host over BTLE.
// 1 half: resolve 2-handed key combos e.g: (left-shift-plus-k == K)
//
// Here is how it's implemented.
// Left hand contains:
// - BT serial slave
//
// Right hand contains:
// - BT serial master
// - BT HID
//
// Updates are synchronous and blocking:
// 1. Right asks Left for an update.
// 2. While waiting for a reply, Right updates itself.
// 3. Right waits for an update from Left.
// 4. Right resolves both updates into 1 and sends to host.

void setup(){
}

void loop(){
}
