#!/bin/bash

num=$1

if((num==2))
then
	echo "Prime"
	exit
fi
if((num%2==0))
then
	echo "Not A Prime"
	exit
fi
for((i=3;i<num/2;i+=2))
do
	if(((num%i)==0))
	then
		echo "Not A Prime"
		exit		
	fi
done
echo "Prime"
