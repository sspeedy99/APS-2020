for _ in range(int(input())):
	n = int(input())
	inp = list(map(int,input().split()))
	ans = 0
	odd_so_far = 0

	for i in range(n):
		if inp[i]&1:
			odd_so_far += 1

		if inp[i]%4 == 0:
			ans += (n-i) + ((odd_so_far * (odd_so_far + 1)) / 2) + (odd_so_far * (n-i))
			odd_so_far = 0

		if inp[i]%4 == 2:
			nxt_idx = n
			for j in range(i+1,n):
				if inp[j]%2 == 0:
					nxt_idx = j
					break

			ans += (n-nxt_idx) + ((odd_so_far * (odd_so_far + 1)) / 2) + (odd_so_far * (n-nxt_idx))
			odd_so_far = 0


	ans += (odd_so_far * (odd_so_far + 1)) / 2

	print(int(ans))