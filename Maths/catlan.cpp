#include <bits/stdc++.h>
using namespace std;
using vi = vector <int> ;


#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define ll long long
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



const int N=1e5+5;

unsigned ll catalanDP(unsigned ll n) {
	unsigned ll dp[n+1];
	dp[0] = dp[1] = 1;

	repi(i,2,n) {
		dp[i] = 0;
		rep(j,i)
			dp[i] += dp[j] * dp[i-j-1];
	}

	return dp[n];
}

int32_t main()
{
	IOS;
	rep(i,10)
		cout<<catalanDP(i)<<endl;
	return 0;
}


 

 
