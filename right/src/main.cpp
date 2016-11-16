/* m30c9 -- keyboard firmware for Teensy 3.0
   https://github.com/hoosierEE/m30c9 */
#include <Arduino.h>
#include <m20c9.hpp>

/* HID keyboard data rate limited to 1ms. */
const uint32_t rate{10};/* 10ms */
elapsedMillis t;

/* Both: scan own switches, send/receive messages from other half.
   1 half: commuincate with host over BTLE.
   1 half: resolve 2-handed key combos e.g: (left-shift-plus-k == K)

   Here is how it's implemented.
   Left hand contains:
   - BT serial slave

   Right hand contains:
   - BT serial master
   - BT HID

   Updates are synchronous and blocking:
   1. Right asks Left for an update.
   2. While waiting for a reply, Right updates itself.
   3. Right waits for an update from Left.
   4. Right resolves both updates into 1 and sends to host.
*/
void setup(){
}

void loop(){
}
