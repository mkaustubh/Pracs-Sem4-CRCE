#!/bin/awk -f
BEGIN {
	print "Start";
	sum=0;
}
{
	cost = ($3 * $4)
	print $1 " Rate = " cost
	sum = sum + cost
}
END {
	print "Total Rate = " sum;
}