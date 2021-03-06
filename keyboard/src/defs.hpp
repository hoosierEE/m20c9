// defs.hpp -- common types and HAL definitions
#pragma once
#include <inttypes.h>
#include <array>

const uint8_t cols{5},rows{4},caps{9};
using std::array;


// PINS
const array<uint8_t,caps>tnsy_cap_pins{0,1,15,16,17,18,19,22,23};
const array<uint8_t,cols>tnsy_col_pins{2,5,6,7,8};
const array<uint8_t,rows>tnsy_row_pins{10,11,12,14};


// TYPES
typedef array<int,caps> CapsRaw; // Raw touchRead value
typedef array<bool,caps> CapsTouched; // Was cap threshold exceeded?

// MechLayer is 2D array of printable characters, mapped to a switch matrix.
typedef const array<array<int,cols>,rows> MechLayer; // ASCII (0-127) and MODIFIERKEY_FOO (57345+)
typedef array<array<bool,cols>,rows> MechsPressed; // bitvector to select ASCII chars from MechLayer

