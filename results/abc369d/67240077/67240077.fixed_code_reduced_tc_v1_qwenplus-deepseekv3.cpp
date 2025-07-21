#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll dp[MAXN][2]; // dp[i][0] even count, dp[i][1] odd count

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    dp[0][0] = 0; // even count initially
    dp[0][1] = -INF; // impossible to have odd count initially
    
    for (ll i = 1; i <= n; i++) {
        // Option 1: do not take a[i]
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = -INF; // can't have odd count if we don't take it
        
        // Option 2: take a[i]
        // From even count (0), adding a[i] makes count odd (1)
        ll val1 = dp[i-1][0] + a[i];
        if (val1 > dp[i][1]) {
            dp[i][1] = val1;
        }
        
        // From odd count (1), adding a[i] makes count even (0), so multiply by 2
        ll val2 = dp[i-1][1] + 2 * a[i];
        if (val2 > dp[i][0]) {
            dp[i][0] = val2;
        }
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}