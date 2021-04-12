/* Author - sspeedy99
*/

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
#define int long long int
 
 
const int N=1e6+5;
const int mod = 1e9+7;
const ll mex = 2e5 + 5;

vector<vector<int>> mat;

void readInp(int n, int m){
    mat.resize(n+1);
    repi(i,0,n) mat[i].resize(m+1);
    repi(i,0,n)
        repi(j,0,m)
            if(i ==0 || j==0) mat[i][j] = 0;
            else cin>>mat[i][j];
}

void overRide(int n, int m){
    repi(i,0,n){
        int s = 0;
        repi(j,0,m){
            mat[i][j] += s;
            s = mat[i][j];
        }
    }
}

void inverseOverride(int n, int m){
    repi(j,0,m){
        int s = 0;
        repi(i,0,n){
            mat[i][j] += s;
            s = mat[i][j];
        }
    }
}

int solve(int n, int m, int k){
    int u = min(n,m);
    int ans = 0;
    repi(v,1,u)
        repi(i,v,n)
            repi(j,v,m)
                if((mat[i][j]+mat[i-v][j-v]-mat[i][j-v]-mat[i-v][j])/(v*v)>=k)
                    ans += 1;
    return ans;
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int t;
    cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        readInp(n,m);
        overRide(n,m);
        inverseOverride(n,m);
        int ans = solve(n,m,k);
        cout<<ans<<endl;
        mat.clear();

    }
    return 0;
}