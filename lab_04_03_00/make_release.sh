#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c main.c
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c my_funcs.c
gcc -o app.exe main.o my_funcs.o