def linearSearch(linear, n):
    for i in range(0,len(li)):
        if n == li[i]:
            print('\nElement '+str(li[i])+' found at location '+str(i+1))
            return 
        print('\nelement not present\n')

n = int(input('\nEnter the size of the list\n'))
li=[]
for i in range(0,n):
    li.append(int(input('\nEnter an element\n')))

m = int(input('\nEnter the element to be found\n '))

linearSearch(li,m)

