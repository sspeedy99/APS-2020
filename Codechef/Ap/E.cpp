/******************************************
*    AUTHOR:         BHUVNESH JAIN        *
*    INSTITUITION:   BITS PILANI, PILANI  *
******************************************/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL; 
typedef long double LD;
 
const int MAX = 2e5 + 5;
const int LIM = 15;
 
int add(int a, int b, int c) {
    int res = a + b;
    return (res >= c ? res - c : res);
}
 
int mod_neg(int a, int b, int c) {
    int res; if(abs(a-b) < c) res = a - b;
    else res = (a-b) % c;
    return (res < 0 ? res + c : res);
}
 
int mul(int a, int b, int c) {
    LL res = (LL)a * b;
    return (res >= c ? res % c : res);
}
 
int power(int a, int b) {
    int x = 1;
    for(int i = 1; i <= b; ++i) x *= a;
    return x;
}
 
template<typename T> T extended_euclid(T a, T b, T &x, T &y) {
    T xx = 0, yy = 1; y = 0; x = 1;
    while(b) {
        T q = a / b, t = b;
        b = a % b; a = t;
        t = xx; xx = x - q * xx;
        x = t; t = yy;
        yy = y - q * yy; y = t;
    }
    return a;
}
 
template<typename T> T mod_inverse(T a, T n) {
    T x, y, z = 0; 
    T d = extended_euclid(a, n, x, y);
    return (d > 1 ? -1 : mod_neg(x, z, n));
}
 
int a[MAX];
int pre[LIM];
int cnt[LIM];
int rem[LIM];
vector<pair<int,int>> factors;
vector<int> mod;
vector<pair<int,pair<int,int>>> crt;
 
void update(int a, bool add) {
    if (a == 1) return ;
    int idx = 0;
    for(auto it : factors) {
        int p = it.first, e = it.second, x = 0;
        while(a % p == 0) a /= p, x += 1;
        if (add) cnt[idx] += x;
        else cnt[idx] -= x;
        pre[idx] = mul(pre[idx], a, mod[idx]);
        if (cnt[idx] >= e) rem[idx] = 0;
        else rem[idx] = mul(pre[idx], power(p, cnt[idx]), mod[idx]);
        idx += 1;
    }
}
 
void pre_process() {
    int a = 1, b = 1, m = mod[0];
    crt.push_back({mod[0], {a, b}});
    for(int i = 1; i < mod.size(); ++i) {
        a = mod_inverse(m, mod[i]);
        b = mod_inverse(mod[i], m);
        crt.push_back({m, {a, b}});
        m *= mod[i];
    }
}
 
int find_crt() {
    int ans = rem[0], m = crt[0].first, a, b;
    for(int i = 1; i < mod.size(); ++i) {
        a = crt[i].second.first;
        b = crt[i].second.second;
        m = crt[i].first;
        ans = (1LL*ans * b * mod[i] + 1LL*rem[i] * a * m) % (m * mod[i]);
    }
    return ans;
}
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k = 4;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int up = sqrt(k);
    for(int i = 2; i <= up; ++i) {
        if (k % i == 0) {
            int x = 0;
            while(k % i == 0) k /= i, x += 1;
            factors.push_back({i, x});
            mod.push_back(power(i, x));
            if (k == 1) break;
        }
    }
    if (k > 1) {
        factors.push_back({k, 1});
        mod.push_back(k);
    }
    for(int i = 0; i < mod.size(); ++i) rem[i] = pre[i] = 1;
    pre_process();
    int j = 0, prod = 1;
    LL ans = 0;
    for(int i = 0; i < n; ++i) {
        while(j < n) {
            if (prod == 0 && i <= j) break;
            update(a[j], true);
            prod = find_crt();
            j += 1;
        }
        if (prod == 0 && i <= j) ans += n - j + 1;
        update(a[i], false);
        prod = find_crt();
    }
    printf("%lld\n", ans);
    }
    
    return 0;
}
