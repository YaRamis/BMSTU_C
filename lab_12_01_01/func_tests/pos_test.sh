#!/bin/bash
./app.exe $(cat func_tests/pos_$1_args.txt)
rc=$?

diff -B -b func_tests/output_file_temp.txt func_tests/pos_$1_out.txt > /dev/null
rc_2=$?

if [ $rc_2 == 0 ] && [ $rc == 0 ]
then
    echo -e POS_"$1": "\e[32mPASSED\e[0m"
else
    echo -e POS_"$1": "\e[31mFAILED\e[0m" rc=$rc
    diff func_tests/output_file_temp.txt func_tests/pos_$1_out.txt
fi

if [ -e "func_tests/output_file_temp.txt" ]
then
    rm "func_tests/output_file_temp.txt"
fi
