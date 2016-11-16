// Left side mechanical keymap
#ifdef m20c9_LEFT
MechLayer MLdefault{{
        {'1', '2', '3', '4', '5'},
        {'q', 'w', 'e', 'r', 't'},
        {'a', 's', 'd', 'f', 'g'},
        {'z', 'x', 'c', 'v', 'b'}}};

MechLayer MLshifted{{
        {'!', '@', '#', '$', '%'},
        {'Q', 'W', 'E', 'R', 'T'},
        {'A', 'S', 'D', 'F', 'G'},
        {'Z', 'X', 'C', 'V', 'B'}}};

MechLayer MLsymbols{{
        {' ', ' ', ' ', ' ', ' '},
        {'@', '#', '$', '%', '['},
        {' ', '-', '+', '=', '('},
        {'_', '~', '`', '!', '{'}}};

// TODO: Left side capacitive keymap

#else

// Right side mechanical keymap
MechLayer MLdefault{{
        {'6', '7', '8', '9', '0'},
        {'y', 'u', 'i', 'o', 'p'},
        {'h', 'j', 'k', 'l', '\''},
        {'n', 'm', ',', '.', '-'}}};

MechLayer MLshifted{{
        {'^', '&', '*', '(', ')'},
        {'Y', 'U', 'I', 'O', 'P'},
        {'H', 'J', 'K', 'L', '"'},
        {'N', 'M', '?', '!', ':'}}};

MechLayer MLsymbols{{
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
