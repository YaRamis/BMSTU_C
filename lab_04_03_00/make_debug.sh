#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -g3 -c -coverage main.c
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -g3 -c -coverage my_funcs.c
gcc -o app.exe --coverage main.o my_funcs.o