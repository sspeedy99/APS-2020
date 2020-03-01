// C++ program for coin change problem. 
#include<bits/stdc++.h> 

using namespace std; 

int count( int S[], int m, int n ) 
{ 
	// table[i] will be storing the number of solutions for 
	// value i. We need n+1 rows as the table is constructed 
	// in bottom up manner using the base case (n = 0) 
	int table[n+1]; 

	// Initialize all table values as 0 
	memset(table, 0, sizeof(table)); 

	// Base case (If given value is 0) 
	table[0] = 1; 

	// Pick all coins one by one and update the table[] values 
	// after the index greater than or equal to the value of the 
	// picked coin 
	for(int i=0; i<m; i++) 
		for(int j=S[i]; j<=n; j++) 
			table[j] += table[j-S[i]]; 

	return table[n]; 
} 


// Driver Code 
int main() 
{ 
	int arr[] = {49, 22 ,45, 6 ,11, 20, 30, 10, 46, 8, 32, 48, 2 ,41, 43, 5, 39, 16, 28, 44, 14, 4 ,27, 36}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	int n = 15; 
	cout << count(arr, m, n); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai(Abby_akku) 
