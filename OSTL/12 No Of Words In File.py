# Open File
# Read Each Line of File
# Split Each Line of File
# Into A List of Words
# Keep Adding to Length of Words
# Enjoy

def CountWords():
   f = open("Samples/Sample Reverse.txt");
   count = 0;
   for line in f:
      words = line.split();
      count = count + len(words);
   f.close();
   return count;

print ("No Of Words is", CountWords())