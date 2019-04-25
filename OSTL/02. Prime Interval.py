import math

def CheckPrime(num):
	# 2 is Prime
	if num == 2:
		return True;
	# Divide By 2 Is Not Prime
	if num % 2 == 0:
		return False;
	# Start from 3 till Num
	# And Increment All Indices by 2
	for i in range(3, num, 2):
		if(num%i == 0):
			return False;
	return True;

def ShowPrime(start, end):
	for i in range(start, end):
		if CheckPrime(i):
			print (i, " is Prime");

ShowPrime(1,21);