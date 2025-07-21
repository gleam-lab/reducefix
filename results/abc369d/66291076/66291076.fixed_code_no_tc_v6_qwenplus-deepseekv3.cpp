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

    // dp[i][0] = max exp when i-th is attacked with normal attack (even count)
    // dp[i][1] = max exp when i-th is attacked with special attack (odd count)
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    
    dp[0][0] = a[0];
    dp[0][1] = 0;
    
    dp[1][0] = a[0] + 2 * a[1];
    dp[1][1] = a[1];
    
    for (int i = 2; i < n; ++i) {
        // To have even count at i, previous must be even (normal attack)
        // or odd (special attack) with gap >= 2
        dp[i][0] = max(dp[i-1][1] + 2 * a[i], dp[i-2][0] + a[i]);
        
        // To have odd count at i, previous must be odd (special attack)
        // or even (normal attack) with gap >= 2
        dp[i][1] = max(dp[i-1][0] + a[i], dp[i-2][1] + 2 * a[i]);
    }
    
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}