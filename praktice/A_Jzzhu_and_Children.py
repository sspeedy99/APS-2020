import math
n,m = map(int,input().split())
inp = list(map(int, input().split()))
ans = -1
msf = -1
for i in range(n):
    temp = math.ceil(inp[i]/m)
    if temp >= msf:
        msf = temp
        ans = i+1
print(ans)
