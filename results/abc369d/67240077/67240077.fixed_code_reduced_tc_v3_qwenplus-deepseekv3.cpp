#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll dp[MAXN][2]; // dp[i][0] = not take i, dp[i][1] = take i

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    dp[1][0] = 0;
    dp[1][1] = a[1];
    for(ll i=2;i<=n;i++){
        // Option 1: do not take a[i]
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        // Option 2: take a[i]
        // If previous was not taken, take a[i] as is
        ll take1 = dp[i-1][0] + a[i];
        // If previous was taken, and count is odd, double a[i]
        ll take2 = dp[i-1][1] + (a[i] * 2);
        dp[i][1] = max(take1, take2);
    }
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}