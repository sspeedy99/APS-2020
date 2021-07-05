/* Author - sspeedy99
Editorial - Simple Solution
The solution is pretty straight forward. We only have to find the shortest path between 1 to n in the given undricted path. Simple BFS is enough, use a vector to print the path */




#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
using vi = vector<int>;
using vii = vector<long long>;
 
 
// Policy based data structure - order statistics tree with node update
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;
 
 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define fill(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(itr, x)  for (auto itr : x)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())
#define show(container) for(auto it: container) cout<<it<<" "
 
 
const int N=1e6+5;
const int mod = 1e9+7;



int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vii inp(n+1);
        repi(i,1,n) cin>>inp[i];
        vii dp(n+1,-1);
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1];
            for(int j =1; j<i; j++){
                if(i%j ==0 && inp[j] <= inp[i])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ll ans = INT32_MIN;
        for(int i=1; i<=n; i++)
            ans = max(ans, dp[i]);
        
        cout<<ans<<endl;
    }
    
    return 0;
}