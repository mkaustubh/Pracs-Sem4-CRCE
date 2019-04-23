process_queue = []
total_wtime = 0
total_tat=0
ct = 0
n = int(input('Enter the total no of processes: '))
for i in range(n):
    at = 0
    bt = 0
    process_queue.append([])#append a list object to the list
    process_queue[i].append(int(input('Enter p_id: ')))
    #at = int(input('Enter p_arrival: '))
    process_queue[i].append(0)
    bt = int(input('Enter p_bust: '))
    process_queue[i].append(bt)
    print('')

process_queue.sort(key = lambda process_queue:process_queue[2]) #sort by burst time

for i in range(n):
	ct += process_queue[i][2]
	process_queue[i].append(ct)
	tat = ct-0 #if at = 0, modify for general case
	process_queue[i].append(tat)
	total_tat += tat
	wt = tat - process_queue[i][2]
	total_wtime += wt #ct-bt
	process_queue[i].append(wt)

print ('ProcessName\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitTime')

for i in range(n):
    print (process_queue[i][0],'\t\t',process_queue[i][1],'\t\t',process_queue[i][2],'\t\t',process_queue[i][3],'\t\t',process_queue[i][4],'\t\t',process_queue[i][5])
    
print ('Total waiting time: ',total_wtime)
print ('Average waiting time: ',(total_wtime/n))
print ('Total turn around time: ',total_tat)
print ('Average turn around time: ',(total_tat/n))