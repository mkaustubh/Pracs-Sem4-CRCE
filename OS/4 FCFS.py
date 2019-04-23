class Process:
	# Call Constructor with Values of ProcessId
	# Arrival Time
	# Burst Time
	def __init__(self, pId, arrival, burst):
		self.processId = pId
		self.burst = burst
		self.arrival = arrival
		self.completion = 0
		self.turnAround = 0
		self.waiting = 0

# Sample Taken from Sir In Notebook
processes=[Process(1,0,2),Process(2,1,3),Process(3,2,5),Process(4,3,4),Process(5,4,6)]

processes = sorted(processes, key=lambda x: x.arrival, reverse=False);

# We Do Not know if any process arrives at 0
# Hence completionTot is actually Arrival Time of First Process
completionTot = processes[0].arrival

for process in processes:

	# If a Process arrives at 3 Seconds
	# But Completion Total Till then is 2 Seconds
	# Then CompletionTotal must be 3 seconds
	# 1 Second is obviously wasted
	if completionTot < process.arrival:
		completionTot = process.arrival

	# Add Completion with Burst
	completionTot = completionTot + process.burst
	
	# Set Current Process Execution End Time
	# as Process Completion Time
	process.completion = completionTot

	process.turnAround = process.completion - process.arrival
	process.waiting = process.turnAround - process.burst

	# Gantt
	print ("Process ", process.processId, " finished at ", process.completion)
print ("Completed in ", completionTot)

turnAroundTot = 0
waitingTot = 0

for process in processes:
	turnAroundTot = turnAroundTot + process.turnAround
	waitingTot = waitingTot + process.waiting

print ("It took TurnAround=", turnAroundTot, " and Waiting = ", waitingTot)
turnAroundAvg = turnAroundTot/len(processes)
waitingAvg = waitingTot/len(processes)
print ("It took Average Turn Around=", turnAroundAvg, " and Average Waiting = ", waitingAvg)
