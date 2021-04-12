import sys

def check():
    print(sys.base_prefix)

for _ in range(int(input())):
    n,m,k = map(int,input().split(" "))
    mat = []
    u = min(n,m)
    ans = 0
    for i in range(0,n): 
        mat.append([int(j) for j in input().split()])

    for i in range(0,n):
        for j in range(0,m):
            if i == 0 or j == 0:
                mat[i][j] = 0
    for i in range(0,n):
        x = 0
        for j in range(0,m):
            mat[i][j] += x
            x = mat[i][j]

    for j in range(0,m):
        x = 0
        for i in range(0,n):
            mat[i][j] += x
            x = mat[i][j]

    for v in range(1,u+1):
        for i in range(v,n):
            for j in range(v,m):
                if((mat[i][j]+mat[i-v][j-v]-mat[i][j-v]-mat[i-v][j]//(v*v)>=k)):
                    ans += 1
    
    print(ans)

    
    
