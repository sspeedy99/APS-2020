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


#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
#define sz(x) (int)((x).sizmedian = *prev(s.find_by_order(k/2));e())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define trace(itr, x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())


const int N=1e5+5;


int solve(vector<int> b, vector<int> g, int n, int m){
    int cnt =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(abs(b[i] - g[j]) <= 1){
                g[j] = N;
                cnt++;
                break;
            }
        }
    }

    return cnt;
}


int main()
{
    // #ifndef ONLINE_JUDGE 
    // // For getting input from input.txt file 
    // freopen("input.txt", "r", stdin); 
  
    // // Printing the Output to output.txt file 
    // freopen("output.txt", "w", stdout); 
    IOS;
    int n,m;
    cin>>n;
    vi boys(n);
    rep(i,n) cin>>boys[i];
    cin>>m;
    vi girls(m);
    rep(j,m) cin>>girls[j];

    sort(all(boys));
    sort(all(girls));
    cout<<solve(boys,girls,n,m)<<endl;
    return 0;
}
