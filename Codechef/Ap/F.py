import random

def genRandom(n,m):
	randomlist = []
	for i in range(n):
		k = random.randint(1,m)
		randomlist.append(k)
	return randomlist

for _ in range(int(input())):
	n,m,k = map(int, input().split())
	for i in range(n):
		inp = map(int,input().split())

	ret = genRandom(n,m)
	for i in ret:
		print(i, end =" ")
	print()


	