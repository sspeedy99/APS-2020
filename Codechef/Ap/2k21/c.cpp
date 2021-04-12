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

vector<int>dp,dp2,inp,inp1;

int check(string s, string t){
    unordered_map<char, vector<int> > mp;
    rep(i,sz(t)) mp[t[i]].pb(i);
    int prev = -1;
    trace(c,s){
        auto it = mp.find(c);
        if(it == mp.end()) return 0;
        auto vec = it->second;
        int pos = upper_bound(all(vec),prev) - vec.begin();
        if(pos == sz(vec)) return 0;
        prev = vec[pos];
    }
    return 1;
} 

void fillDP(string s,int n){
    for (int i = n - 1; i >= 0; --i) {
    dp[i] = dp[i + 1];
    if (s[i] == '0' && inp1[i] < n)
      dp[i] = max(dp[i], dp[inp1[i] + 1] + 1);
    if (s[i] == '1' && inp[i] < n)
      dp[i] = max(dp[i], dp[inp[i] + 1] + 1);
    dp2[i] = dp2[i + 1];
    if (inp1[i] < n)
      dp2[i] = max(dp2[i], dp[inp1[i] + 1] + 1);
  }
}

string eval(string ans,int size,int dumm,int n){
    for (int i = 1; i < size; ++i) {
    if (dumm >= n) {
      ans+='0';
      continue;
    }
    if (inp[dumm] >= n) {
      ans+='0';
      dumm = inp[dumm] + 1;
      continue;
    }
    if (dp[inp[dumm] + 1] < size - i - 1) {
      ans+='0';
      dumm = inp[dumm] + 1;
    } else {
      ans+='1';
      dumm = inp1[dumm] + 1;
    }
    }
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
        string s;
        cin>>s;
        int n = sz(s);
        dp.resize(n+1);dp2.resize(n+1);inp.resize(n+1);inp1.resize(n+1);
        string ans = "1";
        int prev = -1;
        rep(i,n){
            if(s[i] == '0'){
                for(int j = prev+1; j<=i; ++j)
                    inp[j] = i;
                prev = i;
            }
        }
        for(int i = prev+1; i<n; ++i)
            inp[i] = n;
        if(inp[0] == n){
            cout<<"0"<<endl;
            return 0;
        }

        prev = -1;
        rep(i,n){
            if(s[i] == '1'){
                for(int j = prev+1; j<=i; ++j)
                    inp1[j] = i;
                prev = i;
            }
        }
        for(int i = prev+1; i<n; ++i)
            inp1[i] = n;

        dp[n] = dp[n+1] = 0;
        dp2[n] = dp[n+1] = 0;
        fillDP(s,n);
        int size = dp2[0] + 1;
        int dumm = inp1[0] + 1;

  cout << eval(ans,size,dumm,n) << '\n';
  dp.clear();dp2.clear();inp.clear();inp1.clear();
}

    return 0;
}