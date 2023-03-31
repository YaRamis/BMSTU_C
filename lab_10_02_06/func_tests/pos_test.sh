#!/bin/bash
../app.exe < pos_$1_in.txt > output_file_temp.txt
rc=$?

diff -B -b output_file_temp.txt pos_$1_out.txt > /dev/null
rc_2=$?

if [ $rc_2 == 0 ] && [ $rc == 0 ]
then
    echo -e POS_"$1": "\e[32mPASSED\e[0m"
else
    echo -e POS_"$1": "\e[31mFAILED\e[0m" rc=$rc
    diff output_file_temp.txt pos_$1_out.txt
fi

if [ -e "output_file_temp.txt" ]
then
    rm "output_file_temp.txt"
fi
