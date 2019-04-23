#! /bin/bash
echo enter value of n
read n
echo
i=2
printf "1+"
while [ $i -lt $n ]
do
printf "1/$i+"
i=`expr $i + 1`
done
printf "1/$i"
echo