# FIFO
# Implement a Queue
# Check if Match
# If No Match
#	Insert to Back
# If Size is Max
#	Delete from Front when No Match

from collections import deque

slots=3
hits=0

cache=deque([])
refs=[1, 3, 0, 3, 5, 6, 3]

for ref in refs:
	if ref in cache:
		print("The Hit Occured with ",ref)
		hits=hits+1
		continue
	else:
		print("The Miss Occured with ",ref)
		cache.append(ref)
	if len(cache) >= slots + 1:
		cache.popleft()
hitRatio = (hits*100)/len(refs)	
print("Hit Ratio is ", hitRatio)