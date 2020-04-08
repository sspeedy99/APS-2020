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


const ll N = 87000008;
vi primes;

void solve() {
	vector <bool> is_prime(N, true);
	is_prime[0] = is_prime[1] = false;

	for(ll i=2; i*i<=N; i++) {
        if(is_prime[i]) {
            for(ll j= i*i; j<=N; j+=i)
                is_prime[j] = false;
        }
    }

    for(ll i=2; i<=N; ++i)
        if(is_prime[i])
            primes.pb(i);



}

int32_t main()
{
	IOS;
    solve();
    int q,n;
    cin>>q;
    while(q--){
        cin>>n;
        cout<<primes[n-1]<<endl;;
    }

	return 0;
}


 

 
