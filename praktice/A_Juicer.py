n,b,d = map(int, input().split())
inp = list(map(int, input().split()))
ans = 0
fill = 0
for i in inp:
    if i > b:
        continue
    else:
        fill += i
        if fill > d:
            fill = 0
            ans += 1

print(ans)

