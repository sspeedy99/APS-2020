#include <bits/stdc++.h>
using namespace std;

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

typedef vector<int> vi;
typedef long long  ll;

const int N=1e5+5;

int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int dp[n+1][W+1]; 
  
   // Build table dp[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               dp[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]); 
           else
                 dp[i][w] = dp[i-1][w]; 
       } 
   } 
  
   return dp[n][W]; 
} 
int32_t main()
{
	IOS;
	int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    cout<<knapSack(W, wt, val, n)<<endl; 


	return 0;
}


 

 
