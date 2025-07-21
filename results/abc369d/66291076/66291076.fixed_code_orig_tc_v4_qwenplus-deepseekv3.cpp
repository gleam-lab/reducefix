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

    // dp[i][0] = max experience when even times up to i
    // dp[i][1] = max experience when odd times up to i
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][1] = a[0];
    dp[1][0] = a[0] + 2 * a[1];
    dp[1][1] = a[1];

    for (int i = 2; i < n; ++i) {
        // To reach even count at i, we can:
        // 1. Come from even at i-2 and take current with count+1 (becomes odd)
        //    Then adjust to even by adding a[i]
        // 2. Come from odd at i-1 and take current with count+1 (becomes even)
        //    Then adjust to even by adding a[i] * (count+1)
        dp[i][0] = max(dp[i-2][0] + a[i], dp[i-1][1] + 2 * a[i]);
        
        // To reach odd count at i, we can:
        // 1. Come from odd at i-2 and take current with count+1 (becomes even)
        //    Then adjust to odd by adding a[i] * (count+1)
        // 2. Come from even at i-1 and take current with count+1 (becomes odd)
        //    Then adjust to odd by adding a[i]
        dp[i][1] = max(dp[i-2][1] + 2 * a[i], dp[i-1][0] + a[i]);
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}