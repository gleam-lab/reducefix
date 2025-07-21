#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], dp[MAXN][2];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    dp[0][0] = 0;
    dp[0][1] = -INF;
    for(ll i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = a[i] + max(dp[i-1][0], (i >= 2 ? dp[i-1][1] + a[i-1] : -INF));
    }
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}