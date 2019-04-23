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
processes=[Process(1,0,6),Process(2,0,8),Process(3,0,7),Process(4,0,3)]

# Sort on Basis of Burst Time
# Same Arrival Time
processes = sorted(processes, key=lambda process: process.burst, reverse=False);

# We Do Not know if any process arrives at 0
# Hence completionTot is actually Arrival Time of First Process
completionTot = processes[0].arrival

for process in processes:

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
