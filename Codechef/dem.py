from itertools import permutations
perms = [i for i in permutations([0,1,2,3]) if len(set(i))==4] #length 4 permutaions
final = []
# perms = permutations(range(len(arr)))
d= {'A':0, 'B':1, 'C':2, 'D':3, '12': 0, '3':1, '6':2, '9':3}

for _ in range(int(input())):
    arr = [[0]*4 for i in range(4)]
    for i in range(int(input())):
        c,n = map(str, input().split(' '))
        arr[d[c]][d[n]]+=1
        
    # print(arr)
    container=[]
    for movie in perms:
        for time in perms:
            money=[]
            profit=[100,75,50,25]
            for i,j in zip(movie,time):
                money.append(arr[i][j])
                money.sort(reverse =True)
                

            # print(money ,sep =" , ")
            su=0  
            for i,j in zip(money,profit):
                if i > 0:
                    su+=i*j
                else:
                    su-=100
                # print(su)
            container.append(su)

    s=max(container)
    print(s)
    final.append(s)

        

    # max_ = max([[row[y] for row, y in zip(arr, permutation)] for permutation in permutations(range(len(arr)))])
    # max_ = sorted(max_, reverse = True)
    # # print(max_)
  
#     s1 = 100*max_[0]+75*max_[1]+50*max_[2]+25*max_[3]
#     var = max_.count(0)
#     s1 = s1-(100*var)
#     final.append(s1)
#     print(s1)
print(sum(final))