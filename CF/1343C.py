
def calculateMaxSum(n, li): 
	ar =[] 
	ar.append(li[0]) 
	large =[] 
	for j in range(0, n-1): 
		if(li[j]>0 and li[j + 1]>0): 
			ar.append(li[j + 1]) 
		elif(li[j]>0 and li[j + 1]<0): 
			large.append(max(ar)) 
			ar =[] 
			ar.append(li[j + 1]) 
		elif(li[j]<0 and li[j + 1]>0): 
			large.append(max(ar)) 
			ar =[] 
			ar.append(li[j + 1]) 
		else: 
			ar.append(li[j + 1]) 

	large.append(max(ar)) 
	return sum(large) 


for _ in range(int(input())):
    N = int(input())
    inp = list(map(int,input().split()))
    print(calculateMaxSum(N, inp)) 
    