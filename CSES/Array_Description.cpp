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

//find_by_order()->returns an iterator to the k-th largest element(0-based indexing)
//order_of_key()->Number of items that are strictly smaller than our item

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())


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
    int n,m;
    cin>>n>>m;
    vi inp(n+1);
    repi(i,1,n) cin>>inp[i];

    //dp[i][x] = no of valid arrays of size i such that it has x as its last position.
    int dp[n+2][m+2];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int x=1; x<=m; x++){
            //base case
            if(i == 1){
                if(inp[i] == 0 || inp[i] == x)
                    dp[i][x] = 1;
                else 
                    dp[i][x] = 0;
            }
            else {
                if(inp[i] == 0 || inp[i] == x)
                    dp[i][x] = ((dp[i-1][x-1]%mod + dp[i-1][x])%mod + dp[i-1][x+1])%mod;
                else
                    dp[i][x] = 0;
            }
        }
    }


    int ans = 0;
    for(int x=1; x<=m; x++)
        ans = (ans + dp[n][x]) % mod;
    
    cout<<ans<<endl;
   
    return 0;
}


 