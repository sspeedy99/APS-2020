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
#define fill(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)



const int N=1e5+5;

double solve(vector<double> p, int n) {
	//dp[i][j] = j heads in i tosses
	double dp[n+1][n+1];
	fill(dp,0.0);

	//base case - 0 heads in 0 toss.
	dp[0][0] = 1.0;

	//bottom up table fill
	repi(i,1,n) {
		repi(j,0,i) {
			if (j==0)
				dp[i][j] = dp[i-1][j] * (1 - p[i]);
			else 
				dp[i][j] = dp[i-1][j] * (1- p[i]) + dp[i-1][j-1] * p[i];
		}
	}

	//we need the values of only those for the condition that number of head is greater than number of tails
	double ans = 0.0;
	repi(i,(n+1)/2,n)
		ans += dp[n][i];

	return ans;
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	vector<double> p(n);
	rep(i,n)
		cin>>p[i];
	cout<<solve(p,n)<<endl;

	return 0;
}