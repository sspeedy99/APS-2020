n = int(input())
inp = input()
cols = "RGB"
ans = ""
cnt = 0
inp += "X"
ans += inp[0]
for i in range(1,n):
    if inp[i] == inp[i-1]:
        cnt += 1
        ch = inp[i+1]
        for j in cols:
            if j != inp[i] and j != ch:
                ans += j
    else:
        ans += inp[i]

print(cnt)
print(ans)