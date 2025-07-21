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

    // Early return
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // dp[i][j] represents the maximum experience points after processing the first i monsters with j being 0 for even number of flips and 1 for odd number of flips
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = a[0]; // Starting with no flip
    dp[0][1] = 0;   // Starting with one flip is not possible as there's only one monster
    dp[1][0] = 0;   // Starting with no flip is not possible as there's only one monster
    dp[1][1] = a[0] + 2 * a[1]; // Starting with one flip for two monsters

    for (int i = 2; i < n; ++i) {
        dp[i][0] = max(dp[i - 2][0] + 2 * a[i], dp[i - 1][1] + a[i]); // Even flips: either take two flips from the previous step or take one flip and add current monster
        dp[i][1] = max(dp[i - 2][1] + a[i], dp[i - 1][0] + 2 * a[i]); // Odd flips: either take two flips from the previous step or take one flip and add current monster
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;

    return 0;
}