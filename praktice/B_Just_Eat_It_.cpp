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
        ll n, ans, sum1 = 0,msf,csf,msf1,csf1;
        cin>>n;
        vii inp(n);
        rep(i,n){
            cin>>inp[i];
            sum1 += inp[i];
        }
        msf = csf = inp[0];
        for(int i=1; i<n-1; i++){
            csf = max(inp[i],csf+inp[i]);
            msf = max(msf,csf);
        }
        msf1 = csf1 = inp[1];
        for(int i=2; i<n; i++){
            csf1 = max(inp[i],csf1+inp[i]);
            msf1 = max(msf1,csf1);
        }
        msf = max(msf,msf1);
        // // if(msf == sum1) msf = max(msf-inp[0],msf-inp[n-1]);
        // cout<<sum1<<" "<<msf<<endl;

        if(sum1 > msf) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    
    return 0;
}