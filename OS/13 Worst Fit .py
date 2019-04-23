# Algorithm
# Sort All partition on basis of Descending Order
# The Worst Fit will be the first Element that we can fit
# From Descending Order of Partitions
# https://www.geeksforgeeks.org/program-worst-fit-algorithm-memory-management/

processes=[212, 417, 112, 426]
partitions=[100, 500, 200, 300, 600]

# Sort partitions in Descending Order
partitions = sorted(partitions, reverse=True)

for processId in range(0,len(processes)):
	# Set FitDone to Failed Initially
	fitDone = False
	process = processes[processId]
	for partitionId in range(0,len(partitions)):
		partition = partitions[partitionId]
		if(partition >= process):
			fitDone = True
			# Fit Successful Here
			partitions[partitionId] = partitions[partitionId] - processes[processId]
			# ReSort the Partition after Updating Previously Consumed Memory
			partitions = sorted(partitions, reverse=True)
			break
	if (fitDone):
		print ("Process Value " , process, " Inserted")
	else:
		print ("Process Value " , process, " Not Inserted")
