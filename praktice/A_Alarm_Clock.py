import math
for _ in range(int(input())):
    a,b,c,d = map(int, input().split())
    if c - d == 0:
        ans = -1
    else:
        x = math.ceil((a-b)/(c-d))
        ans = b + (x * c)

    print(ans)