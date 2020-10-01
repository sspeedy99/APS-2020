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
#define sz(x) (int)((x).size()
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
    int n;
    cin>>n;
    char inp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>inp[i][j];

    int dp[n+1][n+1];

    // dp[i][j] = no of ways to reach (i,j) from (0,0)

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(inp[i][j] == '.') dp[i][j] = 0;
            else dp[i][j] = -1;
        }
    }


    if(dp[0][0] == -1) cout<<0<<endl;

    else if(dp[n-1][n-1] == -1) cout<<0<<endl;

    else{
            for(int i=0; i<n; i++){
        if(dp[i][0] == 0)
            dp[i][0] = 1;
        else 
             break;
    }

    for(int j=1; j<n; j++){
        if(dp[0][j] == 0)
            dp[0][j] = 1;
        else 
            break;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(dp[i][j] == -1)
                continue;
            if(dp[i-1][j] > 0)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if(dp[i][j-1] > 0)
                dp[i][j] = (dp[i][j] + dp[i][j-1]) %mod;
        }
    }

    cout<<dp[n-1][n-1]<<endl;;
    }





    return 0;
}


 