about =: 0 : 0
This script is intended to run as a post-commit hook, and updates the source code to match the documentation.
Think of it as comment-driven development.
)

NB. get headings and data from org-table formatted string
require'regex'
t0=:'\*{2} .*\n(\n.*){3}'rxall fread '../README.org'

get_data=:3 :0
yy=.cutLF y
h=.3}.,>0{yy
d=.'|'cut&>}.yy
h;<d
)

t1=:get_data &> t0

to_c_array=:3 :0
name=.tolower 0{y
data=.('|';'\vert')rplc~ each 1{y
)

