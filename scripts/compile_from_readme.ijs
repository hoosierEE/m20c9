#!/usr/bin/jc

Note 'about this file'
The noun definitions below (default, numeric, shifted, symbols) are turned into:
1. C++ source code definitions
2. README.org tables for user-facing documentation

Usage.
Run the script from the command line:
  ./generate_layouts.ijs

The script will complain if you don't already have J installed.
)

default=:noun define
qwertyuiop
asdfghjkl'
zxcvbnm,._
)

numeric=:noun define
7531902468
1234567890
%/:-()+,.*
)

shifted=:noun define
QWERTYUIOP
ASDFGHJKL"
ZXCVBNM?!-
)

symbols=:noun define
@#$%[]^&*|
 -+=();:/\
_~`!{}<,.>
)

thumbs=:noun define
Shift_L Tab Backspace Space Enter Shift_R
Ctrl_L Meta Alt Alt+Gr Esc Ctrl_R
Layer4 Layer3 Numeric Symbol
)
