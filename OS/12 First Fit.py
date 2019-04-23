# Algorithm
# Add First Element that Fits
# Into List of Partitions

processes=[300,25,125,50]
partitions=[150,350]

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
			break
	if (fitDone):
		print ("Process Value " , process, " Inserted")
	else:
		print ("Process Value " , process, " Not Inserted")
