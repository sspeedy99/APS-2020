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
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		int cnt = 0;
		for(int i=1; i<s.size(); i++){
			if((s[i-1] == 'x' && s[i] == 'y') || (s[i-1] == 'y' && s[i] == 'x')) {
				cnt++;
				s[i-1] = 'a';
				s[i] = 'b';
			}
		}

		cout<<cnt<<endl;

	}


	return 0;
}


 

 
