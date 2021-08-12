
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

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
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
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())
#define show(container)       \
    for (auto it : container) \
    cout << it << " "

const int N = 1e6 + 5;
int mod =1000000007;

int mpow(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int x = mpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
    {
        x = (x * a) % m;
    }
    return x;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);

    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k == 0)
            cout << 1 << endl;
        if (k == 0)
            continue;
        vi dp(k + 1, 0);
        for (int bit = 0; bit < k; bit++)
        {
            if (bit == 0)
            {
                int waysToWin = 0;
                if (n % 2 == 0)
                {
                    waysToWin = (mpow(2, n - 1, mod)) % mod;
                }
                else
                {
                    waysToWin = (1 + mpow(2, n - 1, mod)) % mod;
                }
                dp[bit] = waysToWin;
                continue;
            }

            int waysToWin = 0;

            if (n % 2 == 0)
            {
                waysToWin += mpow(2, ((bit * n)), mod);
                int temp = (((mpow(2, n - 1, mod) - 1 + mod) % mod) * dp[bit - 1]) % mod;
                waysToWin = (waysToWin + temp) % mod;
            }
            else
            {
                waysToWin += dp[bit - 1];
                int temp = (mpow(2, n - 1, mod) * dp[bit - 1]) % mod;
                waysToWin = (waysToWin + temp) % mod;
            }

            dp[bit] = waysToWin;
        }
    cout << dp[k - 1] << endl;
}

return 0;
}