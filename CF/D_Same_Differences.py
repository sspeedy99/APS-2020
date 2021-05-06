def countPairs(arr, n):
	map = dict()
	for i in range(n):
		map[arr[i] - i] = map.get(arr[i] - i, 0) + 1	# To store the required count
	res = 0
	for x in map:
		cnt = map[x]
		res += ((cnt * (cnt - 1)) // 2)

	return res


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    print(countPairs(arr, n))
