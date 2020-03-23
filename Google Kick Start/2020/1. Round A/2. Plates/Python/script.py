
from copy import deepcopy


def plates_score(maxDepth, depth, num_stacks, index, _plates):
	#plates = [[_plates[x][y] for y in range(len(_plates[0]))] for x in range(len(_plates))]
	plates = deepcopy(_plates)

	if (depth >= maxDepth): return 0
	if (len(plates[index]) == 0): return 0

	maxScore = 0
	for i in range(num_stacks):
		if (len(plates[i]) == 0): continue
		value = plates[i].pop() + plates_score(maxDepth, depth + 1, num_stacks, i, plates)
		if (value > maxScore): maxScore = value
	return maxScore


plates = [[]]

T = int(input())
for t in range(T):

	N, K, P = input().split(' ')
	N = int(N)
	K = int(K)
	P = int(P)

	for n in range(N):
		for k in range(K):
			val = int(input())
			plates.append([])
			plates[n].append(val)

	maxScore = 0
	for i in range(P):
		score = plates_score(P, 0, N, i, plates)
		if (score > maxScore): maxScore = score

	print("CASE #{}: {}".format(t+1, maxScore))