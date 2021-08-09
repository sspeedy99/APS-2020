
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
        ll n, init;
        cin>>n>>init;
        vii time(n),low(n), high(n);
        rep(i,n){
            cin>>time[i]>>low[i]>>high[i];
        }
        ll mx_temp = init; ll mn_temp = init;
        ll prev = 0;
        bool flag = false;
        for(int i = 0; i<n; i++){
            mx_temp += time[i] - prev;
            mn_temp -= time[i] - prev;
            if(mx_temp < low[i] || mn_temp > high[i]){
                flag = true;
                break;
            }
            mx_temp = min(mx_temp, high[i]);
            mn_temp = max(mn_temp, low[i]);
            prev = time[i];
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
    return 0;
}