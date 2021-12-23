import math
for _ in range(int(input())):
    n = int(input())
    c = 1
    a = 2
    b = 0
    while(1):
        b = (n-1-a)
        if math.gcd(a,b) == c:
            break
        a += 1
    print(a,b,c)