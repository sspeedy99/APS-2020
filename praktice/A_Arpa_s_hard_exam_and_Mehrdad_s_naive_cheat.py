n = int(input())
ans = 0
j = n%4
if n == 0:
    ans = 1
elif j == 0:
    ans = 6
elif j == 1:
    ans = 8
elif j == 2:
    ans = 4
elif j == 3:
    ans = 2

print(ans)
n