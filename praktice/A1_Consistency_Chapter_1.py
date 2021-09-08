from collections import Counter
f = open("test.txt","r")
o = open("output.txt","w")
rng = int(f.readline())
for j in range(rng):
    inp = str(f.readline()).strip()
    ans = 0
    if len(inp) == 1:
        ans = 0
    else:
        vstr = ''
        cstr = ''
        ans = 0
        for i in inp:
            if i in 'AEIOU':
                vstr += i
            else:
                cstr += i
        
        nV = len(vstr)
        nC = len(cstr)
        if nV == 0:
            ans = nC
        elif nC == 0:
            ans = nV
        else:
            res = Counter(vstr)
            mV = (max(res.values()))
            res = Counter(cstr)
            mC = (max(res.values()))
            ans = (min(((nV-mV) * 2 + (nC)), ((nC-mC) * 2 + nV)))

    o.write("Case #{}: {} \n".format(j+1,ans))
    

