#!/bin/bash
touch func_tests/output_file_temp.txt
./app.exe $(cat func_tests/neg_$1_args.txt)
rc=$?

diff -B -b func_tests/output_file_temp.txt func_tests/neg_$1_out.txt > /dev/null
rc_2=$?

if [ $rc_2 == 0 ] && (("1" < "$rc")) && (("$rc" < "9"))
then
    echo -e NEG_"$1": "\e[32mPASSED\e[0m" rc=$rc
else
    echo -e NEG_"$1": "\e[31mFAILED\e[0m" rc=$rc
fi

if [ -e "func_tests/output_file_temp.txt" ]
then
    rm "func_tests/output_file_temp.txt"
fi
