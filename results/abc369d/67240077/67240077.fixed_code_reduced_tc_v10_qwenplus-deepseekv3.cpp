#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
ll a[MAXN];
ll dp[MAXN][2]; // dp[i][0] = even count, dp[i][1] = odd count

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    dp[0][0] = 0; // even count
    dp[0][1] = -1e18; // odd count (initially impossible)
    
    for (ll i = 1; i <= n; i++) {
        // Option 1: Do not take a[i]
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = -1e18; // cannot have odd count if not taking a[i]
        
        // Option 2: Take a[i]
        // From even count (previous step had even count)
        if (dp[i-1][0] + a[i] > dp[i][0]) {
            dp[i][0] = dp[i-1][0] + a[i];
        }
        if (dp[i-1][0] + a[i] > dp[i][1]) {
            dp[i][1] = dp[i-1][0] + a[i];
        }
        
        // From odd count (previous step had odd count)
        if (dp[i-1][1] + 2 * a[i] > dp[i][0]) {
            dp[i][0] = dp[i-1][1] + 2 * a[i];
        }
        if (dp[i-1][1] + 2 * a[i] > dp[i][1]) {
            dp[i][1] = dp[i-1][1] + 2 * a[i];
        }
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}