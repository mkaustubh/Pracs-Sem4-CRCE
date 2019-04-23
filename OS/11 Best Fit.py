# Algorithm
# Sort All partition on basis of Ascending Order
# The Best Fit will be the first Element that we can fit
# From Ascending Order of Partitions

processes=[300,25,125,50]
partitions=[150,350]

# Sort partitions in Ascending Order
partitions = sorted(partitions, reverse=False)

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
			partitions = sorted(partitions, reverse=False)
			break
	if (fitDone):
		print ("Process Value " , process, " Inserted")
	else:
		print ("Process Value " , process, " Not Inserted")
