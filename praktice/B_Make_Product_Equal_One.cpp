
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
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())
#define show(container) for(auto it: container) cout<<it<<" "
#define int long long
 
 
const int N=1e6+5;
const int mod = 1e9+7;



int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int n;
    cin>>n;
    vi inp(n);
    rep(i,n) cin>>inp[i];
    int k = 0, ans = 0, prod = 1;
    for(int i = 0; i<n; i++){
        if(inp[i] < 0){
            prod *= -1;
            ans += abs(-1 - inp[i]);
        }
        if(inp[i] > 0){
            prod *= 1;
            ans += abs(inp[i] - 1);
        }
        if(inp[i] == 0) k++;
    }
    if (k != 0) ans += k;
    if(k == 0){
        if(prod < 0) ans+=2 ;
    }
    cout<<ans<<endl;
    return 0;
}