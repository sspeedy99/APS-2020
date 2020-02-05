#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

 
const int N=1e5+5;

int maxProd(int n) {
	int dp[n+1];
	dp[0] = dp[1] = 0;

	for(int i=2; i<=n; i++){
		dp[i] = 0;
		for(int j=1; j<=i/2; j++) 
			dp[i] = std::max({dp[i], j*(i-j), j* dp[i-j]});
	}

	return dp[n];
}
 
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	cout<<maxProd(n)<<endl;

	return 0;
}