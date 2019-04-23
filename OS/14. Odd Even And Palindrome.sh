#!/bin/bash

# rev reverses a string


if [ $# -ne 2 ]
then
	echo "Need Two Arguments. Choice and Value"
	exit 1
fi

if [ $1 == "a" ]
then
	val=$2
	if(((val%2)==0))
	then
		echo Even
	else
		echo Odd
	fi
elif [ $1 == "b" ]
then
	reverse=$(echo "$2"|rev)
	if [ $reverse == $2 ]
	then
		echo "Palindrome"
	else
		echo "Not a Palindrome"
	fi
fi	