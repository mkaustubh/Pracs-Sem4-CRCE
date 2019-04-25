# To Extract Digits we will use a simple approach
# First we will convert Number to String
# Then using Splice, Reverse it
# And then Iterate over Reversed Elements

value=153
strV = str(value);
# Splice Up the Digit
# Ends up Reversing it
strRev = strV[::-1];

sum = 0;

for ch in strRev:
   i = int(ch);
   # Sum = Sum + Cube(i)
   sum = sum + i**3;	

if sum == value:
   print ("Is Armstrong");
else:
   print ("Not Armstrong");