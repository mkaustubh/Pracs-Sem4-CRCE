#! /bin/bash
echo "Enter String"
read a 
echo "Enter character to find"
read b
echo $a | grep -b -o $b
