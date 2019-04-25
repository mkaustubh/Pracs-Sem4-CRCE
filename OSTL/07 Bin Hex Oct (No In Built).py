def Convert(decimal, to):
   result=[];
   while decimal != 0:
      digit = decimal%to;
      result.append(digit);
      decimal = int(decimal/to);
   # Result returned in Reversed Order
   result = result[::-1];

   # Hex Available List
   hexList = ['A','B','C','D','E','F'];
   # Convert Any Digit Above 9 to Corresponding Hex
   for elemIt in range(len(result)):
      if result[elemIt] >= 10:
         result[elemIt] = hexList[result[elemIt] - 10];
   return result;

# value
decimal = 44
print("Hex is ", Convert(decimal ,16))
print("Bin is ", Convert(decimal ,2))
print("Oct is ", Convert(decimal ,8))