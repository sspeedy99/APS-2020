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
 
const int N=1e6+5;
const int mod = 1e9+7;

//dp state dp[i][j] = number of ways to distribute j candies to first i students.
//state transition  = dp[i][j] = dp[i-1][0]+dp[i-1][1]....dp[i-1][k] note: This can be done is O(1) time using prefix sum.
int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int n,k;
    cin>>n>>k;
    vi arr(n+1);
    repi(i,1,n) cin>>arr[i];
    int dp[n+1][k+1];
    //base cases
    dp[0][0] = 1;
    for(int i = 1; i<=k; i++) dp[0][i] = 0;
    for(int i=1; i<=n; i++){
        int pref_Sum[k+1];
        pref_Sum[0] = dp[i-1][0];
        //calulate the prefex sum for dp[i-1]th row.
        for(int j = 1; j<=k; j++) 
            pref_Sum[j] = (pref_Sum[j-1]+dp[i-1][j])%mod;
        for(int j =0; j<=k ; j++){
            int ways = pref_Sum[j]; //getting the sum dp[i-1][0...j]
            //we have to remove sum of unreachable elements
            int unreachable = j - arr[i] - 1;
            if(unreachable >= 0){
                ways = (ways - pref_Sum[unreachable]+mod)%mod;
            }
            dp[i][j] = ways;
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
