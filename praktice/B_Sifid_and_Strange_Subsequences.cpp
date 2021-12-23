#include <bits/stdc++.h>
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int qq, n, a[xn], ans, mn;
bool flag;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
	cin >> qq;
	while (qq --){
		cin >> n, ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], ans += (a[i] <= 0);
		sort(a + 1, a + n + 1), mn = inf;
		for (int i = 1; i <= n; ++ i)
			if (a[i] > 0)
				mn = min(mn, a[i]);
		flag = (mn < inf);
		for (int i = 2; i <= n; ++ i)
			if (a[i] <= 0)
				flag &= (a[i] - a[i - 1] >= mn);
		if (flag)
			cout << ans + 1 << endl;
		else
			cout << ans << endl;
	}
 
	return 0;
}