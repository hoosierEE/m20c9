/* m30c9 -- keyboard firmware for Teensy 3.0
   https://github.com/hoosierEE/m30c9 */
#include <Arduino.h>
#include <array>

/* HID keyboard data rate limited to 1ms. */
const uint32_t rate{10};/* 10ms */
elapsedMillis t;

using std::array;
const uint8_t cols{5},rows{4},caps{9};
const array<uint8_t,caps>tnsy_cap_pins{0,1,15,16,17,18,19,22,23};
const array<uint8_t,cols>tnsy_col_pins{2,5,6,7,8};
const array<uint8_t,rows>tnsy_row_pins{10,11,12,14};
typedef const array<array<uint8_t,cols>,rows> MechLayer;

/* Capacitive Keys */


/* Left Hand */
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

/* Right Hand */
MechLayer Rdefault{{
        {'6', '7', '8', '9', '0'},
        {'y', 'u', 'i', 'o', 'p'},
        {'h', 'j', 'k', 'l', '\''},
        {'n', 'm', ',', '.', '-'}}};

MechLayer Rshifted{{
        {'^', '&', '*', '(', ')'},
        {'Y', 'U', 'I', 'O', 'P'},
        {'H', 'J', 'K', 'L', '"'},
        {'N', 'M', '?', '!', ':'}}};

MechLayer Rsymbols{{
        {' ', ' ', ' ', ' ', ' '},
        {']', '^', '&', '*', '|'},
        {')', ';', ':', '/', '\\'},
        {'}', '<', ',', '.', '>'}}};

/* Both: scan own switches, send/receive messages from other half.
   1 half: commuincate with host over BTLE.
   1 half: resolve 2-handed key combos e.g: (left-shift-plus-k == K)
*/
void setup(){
}

void loop(){
}
