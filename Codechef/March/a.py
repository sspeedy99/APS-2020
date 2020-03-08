from collections import defaultdict 

for _ in range(int(input())):
	n,m = map(int,input().split())
	f = list(map(int,input().split()))
	p = list(map(int,input().split()))

	res = defaultdict(int) 
	for i,j in zip(f,p):
		res[i] += j

	print(min(res.values())) 
