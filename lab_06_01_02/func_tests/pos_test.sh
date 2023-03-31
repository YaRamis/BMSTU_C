#!/bin/sh
../app.exe $(cat pos_$1_args.txt) > "output_file_temp.txt"
rc=$?

{
FC output_file_temp.txt pos_"$1"_out.txt
rc_2=$?
} &> /dev/null

if [ $rc_2 == 0 ] && [ $rc == 0 ]
then
echo -e POS_"$1": "\e[32mPASSED\e[0m"
else
FC output_file_temp.txt pos_"$1"_out.txt
echo -e POS_"$1": "\e[31mFAILED\e[0m"
fi
rm "output_file_temp.txt"
