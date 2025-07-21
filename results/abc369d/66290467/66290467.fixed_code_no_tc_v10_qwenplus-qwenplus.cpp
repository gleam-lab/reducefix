#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // Early return for small cases
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp[i] = maximum XP up to monster i
    vector<ll> dp(n);

    // Base cases
    dp[0] = a[0];                      // Only one way to defeat first monster
    dp[1] = max(a[0] + a[1], a[0] * 2); // Either normal attack both, or special on second

    // DP recurrence
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1] + a[i],       // Normal attack on current monster
                    dp[i - 2] + 2 * a[i]); // Special attack on current, so skip previous
    }

    cout << dp[n - 1] << endl;

    return 0;
}