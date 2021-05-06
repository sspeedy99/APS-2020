#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

ll dp[3005][3005][2];
ll a[3000];

int main(){
    ll n;
    scanf("%lld",&n);
    ll i,r,j, sum = 0;
    for(i = 0; i<n; i++){
    scanf("%lld",&a[i]);
    sum+=a[i];
    }
    //base case defintion
    for(int i=0 ;i<n; i++){
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for(r = 1; r<n; r++){
        for(i=0; i+r <n; i++){
            j = i+r;
            dp[i][j][0] = max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
            dp[i][j][1] = min(dp[i+1][j][0],dp[i][j-1][0]);
        }
    }
    //maximum value of X
    ll X = dp[0][n-1][0];
    printf("%lld\n",2*X-sum);
    return 0;
}