#pragma once
#include "shared.hpp"
/* Left side mechanical keys */
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
