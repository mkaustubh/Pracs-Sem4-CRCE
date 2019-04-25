string = input('Enter a string')
vowel = 0
consonants = 0

for i in string:
    if(1 == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'):
        vowel += 1
    elif(i == " "):
        pass
    else:
        consonants += 1

print(vowel)
print('\n')
print(consonants)






