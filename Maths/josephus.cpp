// Dynamic programming solution of the josephus problem in O(n) time complexcity // 



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

int josephus(int n, int k) 
{ 

	int *dp = new int[n+1];
	dp[1] = 1;

	repi(i,2,n)
		dp[i] = (dp[i-1] + k-1)% i + 1;

	return dp[n];

} 

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n = 14;
	int k = 2;
	cout<<josephus(n,k)<<endl;

	return 0;
}


 

 
