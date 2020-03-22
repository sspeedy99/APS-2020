#include <bits/stdc++.h>
using namespace std;
using vi = vector<int> ;
using ll = long long;
const int N=1e5+5;
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


int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Initialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given 
// index in BITree.  The given value 'val' is added to 
// BITree[i] and all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
        // Add 'val' to current node of BI Tree 
        BITree[index] += val; 
  
        // Update index to that of parent in update View 
        index += index & (-index); 
    } 
} 
  
// Returns the sum of array from [0, x] 
int sum(int x, int BITTree1[], int BITTree2[]) 
{ 
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x); 
} 
  
  
void updateRange(int BITTree1[], int BITTree2[], int n, 
                 int val, int l, int r) 
{ 
    // Update Both the Binary Index Trees 
    // As discussed in the article 
  
    // Update BIT1 
    updateBIT(BITTree1,n,l,val); 
    updateBIT(BITTree1,n,r+1,-val); 
  
    // Update BIT2 
    updateBIT(BITTree2,n,l,val*(l-1)); 
    updateBIT(BITTree2,n,r+1,-val*r); 
} 
  
int rangeSum(int l, int r, int BITTree1[], int BITTree2[]) 
{ 
    // Find sum from [0,r] then subtract sum 
    // from [0,l-1] in order to find sum from 
    // [l,r] 
    return sum(r, BITTree1, BITTree2) - 
           sum(l-1, BITTree1, BITTree2); 
} 
  
  
int *constructBITree(int n) 
{ 
    // Create and initialize BITree[] as 0 
    int *BITree = new int[n+1]; 
    // for (int i=1; i<=n; i++) 
    repi(i,1,n)
        BITree[i] = 0; 
  
    return BITree; 
} 


int32_t main()
{
	IOS;
	int n = 5;
	int *BITTree1, *BITTree2;

	BITTree1 = constructBITree(n);
	BITTree2 = constructBITree(n);

	// Add 5 to all the elements from [0,4] 
    int l = 0 , r = 4 , val = 5; 
    updateRange(BITTree1,BITTree2,n,val,l,r); 
  
    // Add 2 to all the elements from [2,4] 
    l = 2 , r = 4 , val = 10; 
    updateRange(BITTree1,BITTree2,n,val,l,r); 
  
    // Find sum of all the elements from 
    // [1,4] 
    l = 1 , r = 4; 
    cout << "Sum of elements from [" << l 
         << "," << r << "] is "; 
    cout << rangeSum(l,r,BITTree1,BITTree2) << "\n"; 


	return 0;
}


 

 
