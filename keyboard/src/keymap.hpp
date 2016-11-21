// Capacitive keys
// alt
// ctrl
// gui
// space

// Special keys -- each enables a different MechLayer
// movement
// shift
// editor
// fn

// To build the left side firmware, this variable should be
// specified as a build flag in ../platformio.ini
// ...or left blank to build the right side (default).
#ifdef m20c9_LEFT
#include "keymap_left.hpp"
#else
#include "keymap_right.hpp"
#endif
