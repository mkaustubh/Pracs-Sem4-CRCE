#! /bin/bash
echo "Enter the amount"
read amount
if [ $amount -lt 1000 ]
then 
    tax=`expr $amount \* 2 / 100`
    discount=`expr $amount \* 10 / 100`
else 
    tax=`expr $amount \* 5 / 100`
    discount=`expr $amount \* 20 / 100`
fi
result=`expr $amount + $tax - $discount`
echo "The amount is $result"
