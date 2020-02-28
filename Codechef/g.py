# Python program to check if there is Pythagorean 
# triplet in given array 

# Returns true if there is Pythagorean 
# triplet in ar[0..n-1] 
import math

def isTriplet(ar, n): 
	j = 0
	cnt = 0
	for i in range(n - 2): 
		for k in range(j + 1, n): 
			for j in range(i + 1, n - 1): 
				# Calculate square of array elements 
				x = ar[i]*ar[i] 
				y = ar[j]*ar[j] 
				z = ar[k]*ar[k] 
				if (x == math.ceil(y + z)or y == math.ceil(x + z) or z == math.ceil(x + y)): 
					cnt += 1

	# print(x,y,z)
	# print(math.ceil(y + z) , math.ceil(x + z),math.ceil(x + y))
	
	# If we reach here, no triplet found 
	return cnt


# Driver program to test above function 
ar = [8.94,10,4.47] 
ar_size = len(ar) 

print(isTriplet(ar,ar_size))

# This code is contributed by Aditi Sharma 
