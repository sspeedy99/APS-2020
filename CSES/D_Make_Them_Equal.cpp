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

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define fill(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(itr, x) for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);

    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll sum = 0;
        ll inp[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin >> inp[i];
            sum += inp[i];
        }

        if (sum % n != 0)
            cout << "-1" << endl;
            else{
                vector< pair<long long, pair<long long, long long> > > ans;
    		long long avg = sum/n;
    		for(int i = 2; i <= n; i++)	{
    			if((inp[i] % i) != 0)	{
    				long long val = i - (inp[i]%i);
    				ans.push_back({1, {i, val}});
    				inp[i] += val;
    				inp[1] -= val;
    			}
				ans.push_back({i, {1, inp[i]/i}});
				inp[1] += inp[i];
				inp[i] = 0;
    		}
    		for(int i = 2; i <= n; i++)	{
    			ans.push_back({1, {i, sum/n}});
    		}
    		cout << ans.size() << "\n";
    		for(int i = 0; i < (int)ans.size(); i++)	{
    			cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
    		}
   		}
            }
        

return 0;
}
