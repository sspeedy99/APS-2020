inp = list(map(int, input().split()))
ans = -1
val = sum(inp)
n = len(inp)
if val%n == 0 and val != 0:
    ans = val//n

print(ans)