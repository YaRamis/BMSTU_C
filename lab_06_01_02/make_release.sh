#!/bin/sh
keys="-std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -c"
gcc $keys main.c
gcc $keys my_functions.c
gcc -o app.exe main.o my_functions.o