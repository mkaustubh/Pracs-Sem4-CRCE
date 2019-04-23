# Algorithm
# Create A Class Process
#  Store Usual params in it
#  ProcessId, Burst, Arrival, Completion etc
#  
#  But also create Param
#   <b>*RobinLeft*</b>
#   Set *RobinLeft=Burst*
#  Also IterationCount = 0

# ProcessAppendNotAddedAhead
#  Iterate through all processes
#  Add to Chart all Processes which have
#  SUPER IMP
#  (Arrival <= chart[top].arrival + Quantum) &&&&& Never Before been added
#   Check this by iterationCount = 0

# Main Code
#  Input all Processes
#  Run Sort By Process Arrival Time
# Create a deque chart (use for creating queue)
# Add top Element of Process to Chart
#  First Set Top Element IterationCount as 1

# Loop till Chart Not Empty
# EXTRACT TOP CHART ELEMENT
# Run ProcessAppendNotAddedAhead on Processes & Chart & Quantum
# Compare Process RobinLeft with Quantum
#  If LESS or EQUAL
#   WORK DONE
#   SET COMPLETION = COMPLETION + ROBIN LEFT
#       ROBIN LEFT = 0
#       PROCESS COMPLETION = COMPLETION
#       PROCESS TURN AROUND = PROCESS COMPLETION - PROCESS ARRIVAL
#       PROCESS WAITING = PROCESS TURN AROUND - PROCESS BURST
#       ADD TO *RESULT* LIST
#  ELSE
#   Work is YET TO BE FINISHED
#   SET PROCESS ROBIN LEFT = PROCESS ROBIN LEFT - QUANTUM
#       PROCESS ITERATION COUNT += 1
#       PROCESS ADD TO CHART QUEUE

class Process:
	def __init__(self, processId, arrival, burst):
		self.processId = processId
		self.arrival = arrival
		self.burst = burst
		self.robinLeft = burst
		self.completion = 0
		self.turnAround = 0
		self.waiting = 0
		self.iterationCount = 0

def ProcessAppendNotAddedAhead(processes, chart, quantum):
	for process in processes:
		if process.arrival <= (chart[0].arrival + quantum) and process.iterationCount == 0:
			process.iterationCount = process.iterationCount+1
			chart.append(process)
# Example present in Sir Notebook
processes = [Process(1,5,5),Process(2,4,6),Process(3,3,7),Process(4,1,9),Process(5,2,2), Process(6,6,3)]
quantum = 3

processes = sorted(processes, reverse=False, key=lambda process: process.arrival)

from collections import deque
chart = deque([])

processTop = processes[0]
processTop.iterationCount = 1
chart.append(processTop)

totalTimeLimit = processes[0].arrival
for process in processes:
	if (process.arrival > totalTimeLimit):
		totalTimeLimit = process.arrival
	else:
		totalTimeLimit = process.burst + totalTimeLimit
result = []
completionTime = processes[0].arrival
while len(chart) > 0:
	ProcessAppendNotAddedAhead(processes, chart, quantum)
	process = chart.popleft()
	print(process.robinLeft, " Process ", process.processId)
	if (process.arrival > completionTime):
		completionTime = process.arrival
	if (process.robinLeft <= quantum):
		completionTime += process.robinLeft
		process.completion = completionTime
		process.turnAround = process.completion - process.arrival
		process.waiting = process.turnAround - process.burst
		print ("Process ", process.processId, " done at ", process.completion)
		result.append(process)
	else:
		completionTime += quantum
		process.iterationCount = process.iterationCount + 1
		process.robinLeft -= quantum
		chart.append(process)
turnAroundTot = 0
waitingTot = 0
for process in result:
	turnAroundTot = turnAroundTot + process.turnAround
	waitingTot = waitingTot + process.waiting

print ("It took Waiting =", waitingTot , " and Turn Around= ", turnAroundTot)

turnAroundAvg = turnAroundTot/len(processes)
waitingAvg = waitingTot/len(processes)

print ("It took Avg Waiting =", waitingAvg , " and Avg Turn Around= ", turnAroundAvg)
