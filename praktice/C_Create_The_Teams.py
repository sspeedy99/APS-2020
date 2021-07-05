for _ in range(int(input())):
    n,x = map(int, input().split())
    arr = sorted(list(map(int,input().split())), reverse = True)
    team_size, ans = 1, 0
    for i in arr:
        if i * team_size >= x:
            ans += 1
            team_size = 0
        team_size += 1
    print(ans)