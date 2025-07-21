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

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // dp[i][0] = max experience when even attacks on monster i
    // dp[i][1] = max experience when odd attacks on monster i
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][1] = a[0];
    dp[1][0] = a[0] + 2 * a[1];
    dp[1][1] = a[1];

    for (int i = 2; i < n; ++i) {
        // Current even attacks can come from previous odd attacks + 1 attack (now even)
        // or from previous even attacks + 0 attacks (but we must attack at least once)
        dp[i][0] = max(dp[i-1][1] + 2 * a[i], dp[i-2][0] + 2 * a[i]);
        
        // Current odd attacks can come from previous even attacks + 1 attack
        // or from previous odd attacks + 0 attacks (but we must attack at least once)
        dp[i][1] = max(dp[i-1][0] + a[i], dp[i-2][1] + a[i]);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}