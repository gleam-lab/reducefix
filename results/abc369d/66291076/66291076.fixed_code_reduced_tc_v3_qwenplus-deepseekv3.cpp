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

    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    dp[0][0] = a[0]; // odd count
    dp[0][1] = 0;    // even count (impossible for first monster)
    dp[0][2] = 0;    // skipped
    
    dp[1][0] = a[1]; // odd count
    dp[1][1] = a[0] + 2 * a[1]; // even count
    dp[1][2] = a[0]; // skipped second monster

    for (int i = 2; i < n; ++i) {
        // Current monster is odd count
        dp[i][0] = max(dp[i-1][2], dp[i-2][1]) + a[i];
        
        // Current monster is even count
        dp[i][1] = max(dp[i-1][0], dp[i-2][1]) + 2 * a[i];
        
        // Current monster is skipped
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }
    
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}