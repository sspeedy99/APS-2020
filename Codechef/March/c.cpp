#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N=1e5+5;

int a[16] = {8,7,8,3,1,6,5,8,5,1,4,3,8,7,1,2};
int b[16] = {8,7,6,1,3,8,7,4,1,5,8,7,2,1,7,8};
 
int32_t main()
{
	IOS;
	ll t,x,y;
	cin >> t;
	while(t--) {
		cin>>x>>y;
		if (x == 1 and y == 1){
			cout<< "16"<<endl;
			for(int i =0; i<16; i++)
				cout<<a[i]<<" "<<b[i]<<endl;
		}
		else {
			int alpha = (x+y)/2;
			cout<<"18"<<endl;
			cout<<alpha<<" "<<alpha<<endl;
			cout<<"1"<<" "<<"1"<<endl;
			for(int i =0; i<16; i++)
				cout<<a[i]<<" "<<b[i]<<endl;

		}

	}

	return 0;
}