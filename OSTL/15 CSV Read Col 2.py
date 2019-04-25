import csv

# Open File
f = open("Samples/Sample.csv");
# Pass File Handle
csvR = csv.reader(f);

for row in csvR:
   if (len(row) >= 2):
      # Print Column 2
      print(row[1])

f.close();