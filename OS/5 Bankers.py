def allocation(n, m, allo):
    for i in range(n):
        process=[]
        print(f'For process {i+1}')
        for j in range(m):
            process.append(int(input(f'Enter the allocation for process {j+1} : ')))
        allo.append(process)


def maximum(n, m, maxi):
    for i in range(n):
        process=[]
        for j in range(m):
            process.append(int(input(f'Enter the maximum for process {j+1} : ')))
        maxi.append(process) 

def available(m, avail):
    for i in range(m):
        avail.append(int(input('Enter the available process : ')))

def cal_need(n, m, maxi, allo, need):
    for i in range(n):
        process=[]
        for j in range(m):
            process.append(maxi[i][j] - allo[i][j])
        need.append(process)

def safety(n, m, maxi, avail, work, finish, allo, need):
    completed = False
    while(True):
        for i in range(n):
            check = False
            completed = True
            if(not finish[i]):
                completed = False
                for j in range(m):
                    if(need[i][j] <= work[j]):
                        check = True
                    else:
                        check = False 
                        break
            if(check):
                for j in range(m):
                    work[j] += allo[i][j]
                finish[i] = True
                print(f'Process {i+1}', end = '-->')
        if(completed):
            break

def main():
    n = int(input("Enter the no of processes : "))
    m = int(input("Enter the no of resource type : "))
    
    avail=[]
    maxi=[]
    allo=[]
    need=[]
    finish=[False]*n

    print('Enter the allocation : ')
    allocation(n, m, allo)
    print('Enter the available processes : ')
    available(m, avail)
    print('Enter the maximum : ')
    maximum(n, m, maxi)
    work = avail
    cal_need(n, m, maxi, allo, need)
    print('Order of execution : ')
    safety(n, m, maxi, avail, work, finish, allo, need)
    print(" ")

main()
    