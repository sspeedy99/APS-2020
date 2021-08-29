for _ in range(int(input())):
    n = int(input())
    ans = 0
    for k in range(2,30):
        z = ((2**k)-1)
        if n%z == 0:
            ans = n//z
            break
    print(ans)