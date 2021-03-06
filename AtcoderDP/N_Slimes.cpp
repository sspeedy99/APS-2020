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
const ll inf = 1e18;

//dp state dp[L][R] = min cost from L...R
//state transition  = dp[L][R] = min(dp[L][R],dp[L][i]+dp[i+1][R]+sum(L,R)) for all L<=i<=R-1
int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    ll n,temp = 0,s;
    cin>>n;
    vii arr(n), sum(n,0);
    ll dp[n][n];
    rep(i,n){
        cin>>arr[i];
        temp+= arr[i];
        sum[i] = temp;
    }
    
    for(int L=n-1; L>=0; L--){
        for(int R=L; R<n; R++){
            if(L==R) dp[L][R] = 0;
            else{
                dp[L][R] = inf;
                if(L == 0) s = sum[R];
                else s = sum[R] - sum[L-1];
                for(int i = L; i<= R-1; ++i)
                    dp[L][R] = min(dp[L][R], dp[L][i]+dp[i+1][R]+s);
            }
        }
    }
    
    cout<<dp[0][n-1]<<endl;
    
    return 0;
}
