#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c --coverage main.c
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c --coverage my_string.c
gcc -o app.exe --coverage main.o my_string.o

./app.exe

rc=$?
echo
echo "END TESTING"
echo
if [ $rc == 0 ]
then
echo -e "\e[32mtesting succeeded\e[0m"
else
echo -e "\e[31mtesting failed\e[0m"
fi
echo

echo "CODE COVERAGE REPORT"
echo
gcov -r -f main.c my_string.c