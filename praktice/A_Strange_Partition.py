import math
for _ in range(int(input())):
    n,x = map(int,input().split())
    inp = list(map(int, input().split()))
    mn = math.ceil(sum(inp)/x)
    mx = 0
    for i in inp:
        mx += math.ceil(i/x)
    print(mn,mx)
