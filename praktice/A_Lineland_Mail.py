n = int(input())
inp = list(map(int, input().split()))
for i in range(n):
    if i == 0:
        print(abs(inp[i] - inp[i+1]), abs(inp[i] - inp[n-1]))
    elif i == n-1:
        print(abs(inp[i] - inp[i-1]), abs(inp[i] - inp[0]))
    else:
        print(min(abs(inp[i] - inp[i-1]), abs(inp[i] - inp[i+1])), max(abs(inp[i] - inp[n-1]), abs(inp[i] - inp[0])))