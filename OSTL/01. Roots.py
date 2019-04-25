# We Need Square Root to Find Square Root of Determinant
from math import sqrt

# Form ax**2 + bx + c
a = 1;
b = 3;
c = 1;

# In Py, value**x is same as "value" raised to power "x"
d = (b**2) - (4*a*c);

if (d < 0):
   print ("Roots are Complex");
   exit();

x1 = (-b + sqrt(d))/(2*a)
x2 = (-b - sqrt(d))/(2*a)

print ("Root 1 & 2 are ", x1, " : ", x2)