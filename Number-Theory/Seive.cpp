// Seive of Eratothenes - Finding Prime numbers //


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



const int N=1e6+5;

int is_prime[N+1];

void Seive() {
    repi(i,1,N)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    for(int i=2; i*i<=N; i++) {
        if(is_prime[i]) {
            for(int j= i*i; j<=N; j+=i)
                is_prime[j] = 0
        }
    }
}



int32_t main()
{
	IOS;
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		isPrime(n)?cout<<"yes"<<endl:cout<<"no"<<endl;
	}

	return 0;
}


 

 
