// Left side mechanical keymap
#include "m20c9.hpp"

#ifdef m20c9_LEFT
MechLayer dflt{{
        {'1', '2', '3', '4', '5'},
        {'q', 'w', 'e', 'r', 't'},
        {'a', 's', 'd', 'f', 'g'},
        {'z', 'x', 'c', 'v', 'b'}}};

MechLayer shft{{
        {'!', '@', '#', '$', '%'},
        {'Q', 'W', 'E', 'R', 'T'},
        {'A', 'S', 'D', 'F', 'G'},
        {'Z', 'X', 'C', 'V', 'B'}}};

MechLayer syms{{
        {' ', ' ', ' ', ' ', ' '},
        {'@', '#', '$', '%', '['},
        {' ', '-', '+', '=', '('},
        {'_', '~', '`', '!', '{'}}};
// TODO: Left side capacitive keymap

#else

// Right side mechanical keymap
MechLayer dflt{{
        {'6', '7', '8', '9', '0'},
        {'y', 'u', 'i', 'o', 'p'},
        {'h', 'j', 'k', 'l', '\''},
        {'n', 'm', ',', '.', '-'}}};

MechLayer shft{{
        {'^', '&', '*', '(', ')'},
        {'Y', 'U', 'I', 'O', 'P'},
        {'H', 'J', 'K', 'L', '"'},
        {'N', 'M', '?', '!', ':'}}};

MechLayer syms{{
        {' ', ' ', ' ', ' ', ' '},
        {']', '^', '&', '*', '|'},
        {')', ';', ':', '/', '\\'},
        {'}', '<', ',', '.', '>'}}};
// TODO: Right side capacitive keymap
#endif

MechLayer MLediting{{
        {MODIFIERKEY_CTRL,MODIFIERKEY_SHIFT,MODIFIERKEY_ALT,MODIFIERKEY_GUI},
        {MODIFIERKEY_CTRL,MODIFIERKEY_SHIFT,MODIFIERKEY_ALT,MODIFIERKEY_GUI},
        {MODIFIERKEY_CTRL,MODIFIERKEY_SHIFT,MODIFIERKEY_ALT,MODIFIERKEY_GUI},
        {MODIFIERKEY_CTRL,MODIFIERKEY_SHIFT,MODIFIERKEY_ALT,MODIFIERKEY_GUI}}};
