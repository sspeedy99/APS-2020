ans = 0
mx_price = 101
for i in range(int(input())):
    wt, price = map(int,input().split())
    if price < mx_price:
        mx_price = price
    ans += wt * mx_price

print(ans)
