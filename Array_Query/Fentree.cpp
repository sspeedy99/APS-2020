/* C++ Implementation of Fenwick tree */

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int> ;
using ll = long long;
const int N=1e5+5;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)

int fentree[N], arr[N], n;


//Update the fentree - point update
void update(int i, int x) { // add x at index i
    for(;,x<=n;x+= x&-x)
        fentree[i] += x;

}

int query(int x){ // //returns the sum of first x elements in given array a[]
    int sum = 0;
    for(;, x>0;x-=x&-x)
        sum += fentree[x];
    return sum;
}

int main()
{
     scanf(“%d”, &n);
     int i;
     for(i = 1; i <= n; i++)
     {
           scanf(“%d”, &a[i]);
           update(i, a[i]);
     }
     printf(“sum of first 10 elements is %d\n”, query(10));
     printf(“sum of all elements in range [2, 7] is %d\n”, query(7) – query(2-1));
     return 0;
}