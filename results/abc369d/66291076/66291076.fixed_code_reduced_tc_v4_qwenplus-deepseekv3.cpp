#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // Option 1: Take previous sequence and add current with +1 multiplier
        ll option1 = dp[i-1] + (i+1) * a[i];
        
        // Option 2: Take sequence from i-2 and create a new sequence with current
        ll option2 = (i >= 2 ? dp[i-2] : 0) + 2 * a[i-1] + 3 * a[i];
        
        // Option 3: For i >= 3, take sequence from i-3 and create a new sequence
        ll option3 = (i >= 3 ? dp[i-3] : 0) + 2 * a[i-2] + 3 * a[i-1] + 4 * a[i];
        
        dp[i] = max({option1, option2, option3});
    }

    cout << dp[n-1] << endl;
    return 0;
}