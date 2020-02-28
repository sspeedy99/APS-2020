#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

 
const int INF=1e9+5;
 
int32_t main()
{
	IOS;
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for(int& x : h) {
        scanf("%d", &x);
    }
    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j : {i + 1, i + 2}) {
            if(j < n) {
                dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
            }
        }
    }

    printf("%d\n", dp[n-1]);

	return 0;
}