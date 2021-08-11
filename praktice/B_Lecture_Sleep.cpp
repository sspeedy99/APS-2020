
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
    int n,k;
    cin>>n>>k;
    vi a(n),t(n);
    vi pref(n);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>t[i];

    int ans = 0,add = 0;
    for(int i=0; i<n; i++){
        if(t[i] == 1) {
            ans += a[i];
            a[i] = 0;
        }
    }

    pref[0] = a[0];
    for(int i=1; i<n; i++)
        pref[i] = pref[i-1] + a[i];
    
    for (int i = k - 1; i < n; ++i)
		add = max(add, pref[i] - (i >= k ? pref[i - k] : 0));
    
    ans += add;
    cout<<ans<<endl;
    return 0;
}