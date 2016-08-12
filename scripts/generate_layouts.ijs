#!/usr/bin/jc

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

default=:noun define
 q w e r t y u i o p
 a s d f g h j k l '
 z x c v b n m , . -
)

numeric=:noun define
 7 5 3 1 9 0 2 4 6 8
 1 2 3 4 5 6 7 8 9 0
 % / : - ( ) + , . *
)

shifted=:noun define
 Q W E R T Y U I O P
 A S D F G H J K L "
 Z X C V B N M ? ! _
)

symbols=:noun define
 @ # $ % [ ] ^ & * |
   - + = ( ) ; : / \
 _ ~ ` ! { } < , . >
)

names=:nl 0  NB. names of the above symbol tables
extract=:(_2<@}.\]);._2@".@]  NB. get the data from the named symbol table
NB. echo extract >names

result =: (extract;])&>names
Note 'result looks like this'
┌─────────────────────┬───────┐
│┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐│default│
││q│w│e│r│t│y│u│i│o│p││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││a│s│d│f│g│h│j│k│l│'││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││z│x│c│v│b│n│m│,│.│-││       │
│└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘│       │
├─────────────────────┼───────┤
│┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐│numeric│
││7│5│3│1│9│0│2│4│6│8││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││1│2│3│4│5│6│7│8│9│0││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││%│/│:│-│(│)│+│,│.│*││       │
│└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘│       │
├─────────────────────┼───────┤
│┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐│shifted│
││Q│W│E│R│T│Y│U│I│O│P││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││A│S│D│F│G│H│J│K│L│"││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││Z│X│C│V│B│N│M│?│!│_││       │
│└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘│       │
├─────────────────────┼───────┤
│┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐│symbols│
││@│#│$│%│[│]│^│&│*│|││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││ │-│+│=│(│)│;│:│/│\││       │
│├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤│       │
││_│~│`│!│{│}│<│,│.│>││       │
│└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘│       │
└─────────────────────┴───────┘
)