ans = 0
for i in range(int(input())):
    op = input()
    inc = op.count('X++')
    inc += op.count('++X')
    dec = op.count('X--')
    dec += op.count('--X')
    ans += inc
    ans -= dec

print(dec)

