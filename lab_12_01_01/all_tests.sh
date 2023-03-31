#!/bin/bash
for i in {01..99}
do
    num=$i
    if [ -e "func_tests/pos_${num}_in.txt" ] && [ -e "func_tests/pos_${num}_out.txt" ]
    then
        bash func_tests/pos_test.sh $num
    else
        break
    fi
done

echo

for i in {01..99}
do
    num=$i
    if [ -e "func_tests/neg_${num}_in.txt" ] && [ -e "func_tests/neg_${num}_out.txt" ]
    then
        bash func_tests/neg_test.sh $num
    else
        break
    fi
done
