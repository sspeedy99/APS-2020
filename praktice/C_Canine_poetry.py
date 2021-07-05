for _ in range(int(input())):
    str = input()
    n = len(str)
    vis = [0] * n
    ans = 0
    for i in range(1,n):
        isMarked = 0
        if str[i] == str[i-1] and vis[i-1]:
            isMarked = 1
        if i > 2 and str[i] == str[i-2] and vis[i-2] == 0:
            isMarked = 1
        vis[i] = isMarked
        ans += vis[i]
    print(ans)