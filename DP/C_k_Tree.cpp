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
 
 
const int N=1e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;

void modular_add(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}


int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int n,k,d;
    cin>>n>>k>>d;
    int dp[n+1][2];
    fill(dp,0);
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i<j) break;
            if(j<d){
                modular_add(dp[i][0],dp[i-j][0]);
                modular_add(dp[i][1],dp[i-j][1]);
            }
            else{
                modular_add(dp[i][1],dp[i-j][0]);
                modular_add(dp[i][1],dp[i-j][1]);                
            }
        }
    }
    cout<<dp[n][1]<<endl;
    return 0;
}