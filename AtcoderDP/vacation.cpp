#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

 
const int N=1e5+5;
 
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	
	//dp[i] - Maximum cost of task i
	vector<int>dp(3,0);
	while(n--){

		vector<int>new_dp(3,0);
		vector<int>cost(3);

		for(int i=0; i<3; ++i)
			cin>>cost[i];

		//fix one and take the other two to find the sum
		for(int i=0; i<3; ++i){
			for(int j=0; j<3; ++j){
				if(i!=j)
					new_dp[j] = max(new_dp[j], dp[i]+cost[j]);
			}
		}

		dp = new_dp;
	}

	//output would be the maximum of the dp array
	cout<<*max_element(dp.begin(), dp.end());

	return 0;
}