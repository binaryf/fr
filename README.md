# fr
Fast and easy find and replace tool for large files.

SYNTAX

$ fr file 'from' 'to'

USAGE EXAMPLE

$ fr fr.c while 'HELLO WORLD!' > out.c

INSTALL

gcc -o fr fr.c

sudo mv fr /usr/local/bin/
