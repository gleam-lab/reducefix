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
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // dp[i][0] = max experience when we skip monster i
    // dp[i][1] = max experience when we defeat monster i
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    
    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[1][0] = dp[0][1];
    dp[1][1] = dp[0][1] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // If we skip current monster, we must have defeated previous one
        dp[i][0] = dp[i-1][1];
        
        // If we defeat current monster, we can either:
        // 1. Defeat previous one (get 1x current)
        // 2. Skip previous one (get 2x current)
        dp[i][1] = max(dp[i-1][1] + a[i], dp[i-1][0] + 2 * a[i]);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}