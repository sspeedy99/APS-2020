#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

 
const int N=1e5+5;
 
int32_t main()
{
	IOS;
	int t,n,k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int flag = 0;
		std::vector<int> coins(n);
		std::vector<int> output(n,0);
		for(int i=0; i<n; i++) {
			cin>>coins[i];
			if(k%coins[i]!=0)
				flag = 1;
		}

		for(int i=0; i<n-1; i++) {
			for (int j: {i+1}){
				if (coins[j]%coins[i]!=0){
					flag = 1;
					break;
				}
			}
		}

		if(!flag)
			cout<<"NO";
		else {
			cout<<"YES"<<" ";

			for(int i= n-1; i>=0; i--) {
				if(k <= 0)
					break;
				if(k % coins[i] == 0) {
					output[i] = (k / coins[i]) - 1;
					k -= output[i] * coins[i];
				}
				else {
					output[i] = (k / coins[i]) + 1;
					k -= output[i] * coins[i];
				}
			}

			for(int i=0; i<n; i++)
				cout<<output[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}