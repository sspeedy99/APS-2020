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



int32_t main()
{
	IOS;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vi num(n+1);
        repi(i,1,n) num[i] = i;
        if (n == 1) {
            cout<<"1"<<endl;
            cout<<"1"<<" "<<"1"<<endl;
        }

        //if n is odd
        else if (n&1) {
            cout<<(n-1)/2<<endl;
            cout<<"3"<<" "<<num[1]<<" "<<num[2]<<" "<<num[n]<<endl;
            for(int i=3; i<n-1; i+=2) cout<<"2"<<" "<<num[i]<<" "<<num[i+1]<<endl;

        }
        //if n is even
        else {
            cout<<n/2<<endl;
            for(int i=1; i<n; i+=2) cout<<"2"<<" "<<num[i]<<" "<<num[i+1]<<endl;

        }
}

	return 0;
} 
