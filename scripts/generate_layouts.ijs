#!/usr/local/bin/jc

Note 'about'
The noun definitions below (default, numeric, shifted, symbols) are turned into:
1. C++ source code definitions
2. README.org tables for user-facing documentation

Usage:
1. have J installed 
Run the script from the command line:
  ./generate_layouts.ijs
)


NB. make sure no other J nouns exist
erase each nl 0

default=:0 :0
 q w e r t y u i o p
 a s d f g h j k l '
 z x c v b n m , . -
)

numeric=:0 :0
 7 5 3 1 9 0 2 4 6 8
 1 2 3 4 5 6 7 8 9 0
 % / : - ( ) + , . *
)

shifted=:0 :0
 Q W E R T Y U I O P
 A S D F G H J K L "
 Z X C V B N M ? ! _
)

symbols=:0 :0
 @ # $ % [ ] ^ & * |
   - + = ( ) ; : / \
 _ ~ ` ! { } < , . >
)

names=:nl 0  NB. names of the above symbol tables
extract=:(_2<@}.\]);._2@".@]  NB. get the data from the named symbol table
result=:(extract;])&>names

NB. exports

NB. C++
quote=:'''','''',~]
trailing_comma=:',',~]

NB. org-mode
capitalize=: }.,~[:toupper 0{]
org_table=:'| ',' ',~]

export=:3 :0
'd h'=.y  NB. data;
o_header=.'** ',capitalize h
o_table=.'|',~"1]_40]\,org_table"0;d
c_header=.h  NB. std::vector<blah...>
c_table=.trailing_comma@quote each d
)
