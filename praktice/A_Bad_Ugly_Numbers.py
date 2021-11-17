for _ in range(int(input())):
    n = int(input())
    if n == 1:
        print("-1")
    else:
        ans = "23"
        for i in range(n-2):
            ans += '3'
        print(ans)