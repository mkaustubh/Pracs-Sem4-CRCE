#!/bin/bash

if [ $# -ne 3 ]
then
	echo "3 Arguments. FileName SearchFor ReplaceFor"
	exit 1
fi

# ls -ld displays Owner and Group of Directory
owner=$(ls -ld| awk '{print $3}')
group=$(ls -ld| awk '{print $4}')
echo "Owner is $owner & Group is $group"
# cat displays a file
# wc -l gives no of lines
noOfLines=$(cat "$1"|wc -l)
noOfLines=$(($noOfLines+1))
echo "No of Lines in $1 is $noOfLines"

# cat displays a file
# wc -w gives no of words
noOfWords=$(cat "$1"|wc -w)
echo "No of Words in $1 is $noOfWords"

# cat displays a file
# grep -o outputs all matches 
#  in it's own line
# wc -l gives no of lines
noOfOccur=$(cat "$1"|grep -o $2|wc -l)
echo "No of Occurs of $2 in $1 is $noOfOccur"

# sed modifies file and displays output
#  sed -i modifies same file
#  /s/source/destpattern
#  We Can also add Line Numbers
echo "Replacing $2 with $3"
sed -i "s/"$2"/"$3"/" "$1"
