#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)


const int N=1e5+5;

int32_t main()
{
	IOS;
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int flag = 0;
		vi inp(n);
		//coins[0] = Rs 5 coin, coins[1] = Rs 10 coin, coins[2] = Rs 15 coin
		vi coins(3,0);
		rep(i,n) cin>>inp[i];
		rep(i,n){
			if(inp[i] == 5)
				coins[0]++;
			else if(inp[i] == 10) {
				if(coins[0] > 0) {
					coins[0]--;
					coins[1]++;
				}
				else {
					flag = 1;
					cout<<"NO"<<endl;
					break;
				}
			}
			else {
				if(coins[1] > 0){
					coins[1]--;
					coins[2]++;
				}
				else if(coins[0] > 1) {
					coins[0]-=2;
					coins[2]++;
				}
				else {
					flag = 1;
					cout<<"NO"<<endl;
					break;
				}
			}
		}

		if (flag == 0)
			cout<<"YES"<<endl;

	}


	return 0;
}


 

 
