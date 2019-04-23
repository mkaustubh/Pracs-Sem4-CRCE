BEGIN	{
	FS=","
	OFS=","
}
{
	id=$1
	name=$2
	total=$3+$4+$5+$6+$7
	result=""
	if($3>=30 && $4 >= 30 && $5 >= 40 && $6 >= 40 && $7 >= 40)
		result="PASS"
	else
		result="FAIL"
	print id,name,total,result
}
END	{
}