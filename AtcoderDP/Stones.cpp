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
#define int long long int
 
const int N=1e6+5;
const int mod = 1e9+7;
vector<int>moves;
vector<int>dp;
int n,k;
int solve(){
    for(int i=0; i<=k; i++){
            for(int j = 0; j<n; j++){
                if(moves[j] <= i){
                    if(!dp[i-moves[j]]){
                        dp[i] = 1;
                        break;
                    }
                }
            }
    }
    return dp[k];
}

 
int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    cin>>n>>k;
    moves.resize(n);
    dp.resize(k+1,0);
    rep(i,n) cin>>moves[i];
    int ans = solve();
    if(ans == 1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}