#pragma once
#include "shared.hpp"
/* Right side mechanical keys */
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
