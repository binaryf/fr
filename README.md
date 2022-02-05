# fr

An Easy to use find and replace tool for large files.
Its proven to be right.

## Syntax

```bash

$ fr file 'from' 'to'

```

## Usage example

```bash

$ fr fr.c while 'HELLO WORLD!' > out.c

```

INSTALL

gcc -o fr fr.c

sudo mv fr /usr/local/bin/
