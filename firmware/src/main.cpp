/* m30c9 -- keyboard firmware for Teensy 3.0
   https://github.com/hoosierEE/m30c9 */
#include <Arduino.h>
#include "defs.hpp"

/* HID keyboard data rate limited to 1ms. */
const uint32_t rate{10};/* 10ms */
elapsedMillis t;



/* Both: scan own switches, send/receive messages from other half.
   1 half: commuincate with host over BTLE.
   1 half: resolve 2-handed key combos e.g: (left-shift-plus-k == K)
*/
void setup(){
}

void loop(){
}
