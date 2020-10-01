#include <bits/stdc++.h>
using namespace std;
using vi = vector <int> ;
using ll = long long;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)


// create a map to store solutions of subproblems
unordered_map<string, bool> lookup;

// Return true if there exists a subarray of array[0..n] with given sum
bool subsetSum(int *arr, int n, int sum)
{
	// return true if sum becomes 0 (subset found)
	if (sum == 0)
		return true;

	// base case: no items left or sum becomes negative
	if (n < 0 || sum < 0)
		return false;

	// construct an unique map key from dynamic elements of the input
	string key = to_string(n) + "|" + to_string(sum);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. include current item in the subset (arr[n]) and recur
		// for remaining items (n - 1) with remaining sum (sum - arr[n])
		bool include = subsetSum(arr, n - 1, sum - arr[n]);

		// Case 2. exclude current item n from subset and recur for
		// remaining items (n - 1)
		bool exclude = subsetSum(arr, n - 1, sum);

		// assign true if we can get subset by including or excluding the
		// current item
		lookup[key] = include || exclude;
	}

	// return solution to current sub-problem
	return lookup[key];
}

// Subset Sum Problem
int main()
{
	// Input: set of items and a sum
	int arr[] = { 7, 3, 2, 5, 8 };
	int sum = 14;

	// number of items
	int n = sizeof(arr) / sizeof(arr[0]);

	if (subsetSum(arr, n - 1, sum))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}



 

 
