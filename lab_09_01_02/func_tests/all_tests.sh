#!/bin/sh
for i in {01..99}
do
num=$i
if [ -e "pos_${num}_in.txt" ] && [ -e "pos_${num}_out.txt" ]
then
sh pos_test.sh $num
else
break
fi
done

echo

for i in {01..99}
do
num=$i
if [ -e "neg_${num}_in.txt" ] && [ -e "neg_${num}_out.txt" ]
then
sh neg_test.sh $num
else
break
fi
done
