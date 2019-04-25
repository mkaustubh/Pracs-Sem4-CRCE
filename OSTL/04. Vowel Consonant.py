# We will Use a Very Simple Case
# Input String
# Convert to Lower Case
# We iterate through a String
# We check if it's character
#  'a' < ch < 'z'
#  If Character, we verify if Vowel [a,e,i,o,u]
#  Else, Consonant

string="HeLLo World";

string = string.lower();
vowels=['a','e','i','o','u'];

vowelsCount = 0;
consonants = 0;

for ch in string:
   # Is Character
   if ch >='a' and ch <= 'z':
      if ch in vowels:
         vowelsCount = vowelsCount + 1;
      else:
         consonants = consonants + 1;
      print (ch);

print("No Of Vowels = ", vowelsCount)
print ("No Of Consonants = ", consonants)