#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    // Early returns for small cases
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // dp[i][0] = max experience up to i-th monster with even count
    // dp[i][1] = max experience up to i-th monster with odd count
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[1][0] = a[0] + 2 * a[1];
    dp[1][1] = max(a[0], a[1]);

    for (int i = 2; i < n; ++i) {
        // Current even count comes from:
        // 1. previous even count + current monster (count becomes odd)
        //    but we need even count, so this is invalid
        // 2. previous odd count + current monster with 2x multiplier
        dp[i][0] = dp[i-1][1] + 2 * a[i];
        
        // Current odd count comes from:
        // 1. previous odd count + current monster (count becomes even)
        //    but we need odd count, so this is invalid
        // 2. previous even count + current monster
        dp[i][1] = dp[i-1][0] + a[i];
        
        // Also consider skipping one monster
        if (i >= 2) {
            dp[i][0] = max(dp[i][0], dp[i-2][0] + 2 * a[i]);
            dp[i][1] = max(dp[i][1], dp[i-2][1] + a[i]);
        }
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}