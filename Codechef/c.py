from itertools import permutations
from collections import defaultdict

dick = defaultdict()

dick = {'A':0, 'B':1, 'C':2, 'D':3, '12': 0, '3':1, '6':2, '9':3}
amt = [100,75,50,25]
output = []

def findPermute():
	perms = []
	for i in permutations([0,1,2,3]):
		if len(set(i)) == 4 :
			perms.append(i)
	return perms


def fill(arr, perms):
	temp = []
	for i in perms:
		for j in perms:
			cost = []
			for k,l in zip(i,j):
				cost.append(arr[k][l])
				cost.sort(reverse=True)


			tmp = 0
			for k,l in zip(cost,amt):
				if k > 0:
					tmp += k*l
				else:
					tmp -= 100
			temp.append(tmp)
	return temp

permute = findPermute()

for _ in range(int(input())):
	soln = [[0]*4 for i in range(4)]
	for i in range(int(input())):
		c,n = map(str, input().split(' '))
		soln[dick[c]][dick[n]] += 1

	container = fill(soln,permute)
	sol = max(container)
	print (sol)
	output.append(sol)

print (sum(output))




