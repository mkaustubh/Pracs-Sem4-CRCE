lower_bound = int(input("\nLower Bound\n"))
upper_bound = int(input("\nUpper Bound\n"))

print('Prime numbers between %d and %d are :' % (lower_bound, upper_bound))

for num in range(lower_bound, upper_bound + 1):
    if num > 1:
        for i in range(2,num):
            if (num % i) == 0:
                break
        else:
            print(num)








