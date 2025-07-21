#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (int(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    vector<ll> dp(n + 2, 0); // dp[i]: max experience up to i-th monster (0-based)
    vector<ll> sum(n + 2, 0); // sum[i]: sum of a[0..i-1]

    rep(i, n) sum[i + 1] = sum[i] + a[i];

    dp[1] = a[0];
    if (n >= 2) dp[2] = a[0] + 2 * a[1];

    for (int i = 3; i <= n; ++i) {
        // Option 1: defeat current monster immediately (multiplier 1)
        // Option 2: skip previous monster, defeat current with multiplier 2
        // Option 3: skip previous 2 monsters, defeat current with multiplier 3
        dp[i] = max({
            dp[i - 1] + a[i - 1],
            dp[i - 2] + 2 * a[i - 1],
            dp[i - 3] + 3 * a[i - 1]
        });
        
        // Also consider skipping more monsters if it leads to better total
        for (int k = 4; k <= i; ++k) {
            dp[i] = max(dp[i], dp[i - k] + k * a[i - 1]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}