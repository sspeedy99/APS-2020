#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pb push_back
#define all(v) 

bool getParity(unsigned int n) 
{ 
    bool parity = 0; 
    while (n) 
    { 
        parity = !parity; 
        n     = n & (n - 1); 
    }      
    return parity; 
}
 
const int N=1e5+5;
 
int32_t main()
{
	IOS;
	ll t,n,q,x;
	cin>>t;
	while(t--){
		cin>>n>>q;
		int oddP =0, evenP =0;
		for(int i=0;i<n; i++) {
			cin>>x;
			getParity(x)? oddP++: evenP++;
		}
		// cout<<oddP<<" "<<evenP<<endl;
		while(q--) {
			int val;
			cin>>val;
			getParity(val) ? cout<<oddP<<" "<<evenP<<endl : cout<<evenP<<" "<<oddP<<endl ;
		}
	}

	return 0;
}