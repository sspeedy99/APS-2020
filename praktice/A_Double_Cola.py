n = int(input())
names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
if n < 6:
    print(names[n-1])
else:
    k = n%10
    if k == 6 or k == 7:
        print(names[0])
    if k == 8 or k == 9:
        print(names[1])
    if k == 0 or k == 1:
        print(names[2])
    if k == 2 or k == 3:
        print(names[3])
    if k == 4 or k == 5:
        print(names[4])
