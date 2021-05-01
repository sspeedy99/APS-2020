def preProcess(inp,a):
    n = len(inp)
    for i in range(n):
        for j in range(31):
            if inp[i]&(1<<j):
                a[j]+=1


def getAns(inp,a):
    ans = 0
    for i in range(31):
        if a[i]:
            ans+=1<<i
    return ans

def processQuery(inp,idx,val,a):
    for i in range(31):
        if inp[idx-1]&(1<<i):
            a[i]-=1
    for i in range(31):
        if val&(1<<i):
            a[i]+=1
    inp[idx-1] = val
    return getAns(inp,a)


for _ in range(int(input())):
    a = [0 for i in range(31)]
    n,q = map(int,input().split())
    inp = list(map(int,input().split()))
    preProcess(inp,a)
    print(getAns(inp,a))
    while q!= 0:
        idx,val = map(int,input().split())
        print(processQuery(inp,idx,val,a))
        q-=1
