#!/bin/sh
keys="-std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -g3 -c --coverage"
gcc $keys main.c
gcc $keys my_functions.c
gcc -o app.exe --coverage main.o my_functions.o