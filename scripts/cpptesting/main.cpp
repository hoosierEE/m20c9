#include <inttypes.h>
#include <cstdio>
#include <array>

using std::array;
const uint8_t cols{5},rows{4},caps{9};

/* Physical Pins */
const array<uint8_t,caps>tnsy_cap_pins{0,1,15,16,17,18,19,22,23};
const array<uint8_t,cols>tnsy_col_pins{2,5,6,7,8};
const array<uint8_t,rows>tnsy_row_pins{10,11,12,14};

/* Printable Character Keymap */
typedef const array<array<uint8_t,cols>,rows> Layer;

/* Left Hand */
Layer Ldefault{{
        {'1', '2', '3', '4', '5'},
        {'q', 'w', 'e', 'r', 't'},
        {'a', 's', 'd', 'f', 'g'},
        {'z', 'x', 'c', 'v', 'b'}}
};

Layer Lshifted{{
        {'!', '@', '#', '$', '%'},
        {'Q', 'W', 'E', 'R', 'T'},
        {'A', 'S', 'D', 'F', 'G'},
        {'Z', 'X', 'C', 'V', 'B'}}
};

Layer Lsymbols{{
        {'@', '#', '$', '%', '['},
        {'@', '#', '$', '%', '['},
        {' ', '-', '+', '=', '('},
        {'_', '~', '`', '!', '{'}}
};

/* Right Hand */
Layer Rdefault{{
        {'6', '7', '8', '9', '0'},
        {'y', 'u', 'i', 'o', 'p'},
        {'h', 'j', 'k', 'l', '\''},
        {'n', 'm', ',', '.', '-'}}
};

Layer Rshifted{{
        {'^', '&', '*', '(', ')'},
        {'Y', 'U', 'I', 'O', 'P'},
        {'H', 'J', 'K', 'L', '"'},
        {'N', 'M', '?', '!', ':'}}
};

Layer Rsymbols{{
        {']', '^', '&', '*', '|'},
        {']', '^', '&', '*', '|'},
        {')', ';', ':', '/', '\\'},
        {'}', '<', ',', '.', '>'}}
};

/* Each half scans its set of switches; gets status from its counterpart.
   1 half commuincates with host over BTLE.

   Assuming that BTLE+[other wireless] costs more energy than just
   [other wireless] by itself, we can attempt to equalize energy
   usage by making the non-BTLE side do extra work, such as:

   "should left-shift-plus-k send K?"
*/
int main(){

}
