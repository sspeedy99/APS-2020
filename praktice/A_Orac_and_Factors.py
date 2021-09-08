for _ in range(int(input())):
    n,k = map(int,input().split())
    ans = 0
    if n&1:
        for i in range(3,n+1):
            if n%i == 0:
                p = i
                ans = n + 2 *(k-1) + p
                break
    else:
        ans = n + 2 * (k)
    print(ans)