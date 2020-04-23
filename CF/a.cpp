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
    multimap<int, int> m; 
    multimap<int ,int >:: iterator it;
    while(t--){
        cin>>n;
        vi arr(n);
        rep(i,n) cin>>arr[i];
        rep(i,n)
            m.insert(make_pair(abs(arr[i]-arr[i+1]),arr[i]));
        m.insert(make_pair(abs(arr[0]-arr[n-1]),arr[n-1]));
        int i = 0; 
        for (it = m.begin(); it != m.end(); it++) 
            arr[i++] = (*it).second ; 
        for (int i = 0 ; i < n; i++) 
            cout << arr[i] << " ";
        m.clear();
        cout<<endl;
    }
        
	return 0;
}


 

 
