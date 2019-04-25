num = int(input('\nEnter a number\n'))

sum = 0 

temp = num 
while temp != 0:
    digit = temp % 10 
    sum += digit ** 3
    temp //=10

print(sum)
if num == sum:
    print('\nIt is an armstrong number\n')
else:
    print('\nIt is not an armstrong number\n')














