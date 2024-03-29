// Miller-Rabin Algorithm for primality test (For long long integers) //
//Spoj Question - PON// 


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
#define fill(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)



const int N=1e5+5;


int32_t main()
{
	IOS;
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		isPrime(n)?cout<<"YES"<<endl:cout<<"NO"<<endl;
	}

	return 0;
}


 

 
