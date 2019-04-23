#!/bin/bash

# -f checks if Item is a file
# -d checks if item is a directory

# ls -A lists all subitems
# wc -l returns no of lines

if [ -f "$1" ]
then
	echo "$1 Is File"
elif [ -d "$1" ]
then
	echo "$1 Is Directory"
	noOfFiles=$(ls -A "$1"|wc -l)
	if((noOfFiles==0))
	then
		echo "$1 is Empty"
		rmdir "$1"
	fi
fi