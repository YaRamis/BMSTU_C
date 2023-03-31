#!/bin/bash
touch output_file_temp.txt
../app.exe $(cat neg_$1_args.txt)
rc=$?

diff -B -b output_file_temp.txt neg_$1_out.txt > /dev/null
rc_2=$?

if [ $rc_2 == 0 ] && (("1" < "$rc")) && (("$rc" < "9"))
then
    echo -e NEG_"$1": "\e[32mPASSED\e[0m" rc=$rc
else
    echo -e NEG_"$1": "\e[31mFAILED\e[0m" rc=$rc
fi

if [ -e "output_file_temp.txt" ]
then
    rm "output_file_temp.txt"
fi
