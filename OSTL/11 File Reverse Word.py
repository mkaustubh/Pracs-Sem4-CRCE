# Read a File
# Read a String from File
# Split String to Find Words
# Add Words to List
# Reverse List using Splice Magic
# Write List to File

wordsStraight = []
f = open("Samples/Sample Reverse.txt", "r");
for line in f:
   # Add New Line Character
   wordsStraight.append('\n');
   # Split Line into Words
   words = line.split();
   for word in words:
      wordsStraight.append(word + " ");
f.close();

wordsRev = wordsStraight[::-1]

f = open("Samples/Sample Reverse.txt", "w");
for word in wordsRev:
	f.write (word)
f.close();