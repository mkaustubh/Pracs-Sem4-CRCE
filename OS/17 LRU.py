# LRU
# Implement a Queue
# Check if Match
# If Match
#	Delete from Stack
#	Insert to Back
# If Not Match
# 	Add to List
# If Size is Max
#	Delete from Front when No Match

from collections import deque

cache=deque([])
refs=[7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]
slots=4
hits=0

for ref in refs:
	if ref in cache:
		print("The Hit Occured with ",ref)
		hits=hits+1
		cache.remove(ref)
		cache.append(ref)
		continue
	else:
		print("The Miss Occured with ",ref)
		cache.append(ref)
	if len(cache) >= slots + 1:
		cache.popleft()
hitRatio = (hits*100)/len(refs)	
print("Hit Ratio is ", hitRatio, " with ", hits, " hits and", len(refs)-hits, " misses")