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


void solve(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &x: A) {
        cin >> x;
    }
    vector<int> pos[N + 1];
    for(int i = 0; i < N; ++i) {
        pos[A[i]].push_back(i + 1);
    }

    vector<int> forsize(N + 1, N + 1);
    for(int i = 1; i <= N; ++i) {
        int mxgap = -1;
        if(pos[i].empty()) {
            continue;
        }
        for(int j = 0; j < sz(pos[i]); ++j) {
            if(j == 0) {
                mxgap = max(mxgap, pos[i][j] - 1);
            }
            if(j == sz(pos[i]) - 1) {
                mxgap = max(mxgap, N - pos[i][j]);
            } 
            if(j - 1 >= 0) {
                mxgap = max(mxgap, pos[i][j] - pos[i][j - 1] - 1);
            }
        }
        forsize[mxgap + 1] = min(forsize[mxgap + 1], i);
    }

    int mn = N + 1;
    for(int len = 1; len <= N; ++len) {
        mn = min(mn, forsize[len]);
        if(mn == N + 1)
            cout << -1 << " ";
        else 
            cout << mn << " ";
    }
    cout << '\n';
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1; 
    cin >> T;
    for(int i = 1; i <= T; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
 
/*
Sample inp
*/