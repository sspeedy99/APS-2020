import sys
for _ in range(int(input())):
	min_sf = sys.maxsize
	n,k = map(int,input().split())
	inp = list(map(int,input().split()))
	flag = 0
	ans = 0
	for i in inp:
		if k%i == 0:
			flag = 1
			temp = k//i
			if min_sf > temp:
				min_sf = temp
				ans = i

	if flag == 0:
		print("-1")
	else:
		print(ans)
