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

    vector<ll> dp(n, 0); // dp[i] = max experience up to index i
    vector<ll> skip(n, 0); // skip[i] = max experience if we skip the previous element

    dp[0] = a[0];
    dp[1] = dp[0] + 2 * a[1];
    skip[1] = a[1]; // We can choose to skip a[0]

    for (int i = 2; i < n; ++i) {
        // Option 1: Take current element normally (multiplier is i+1 - count of skips)
        // Option 2: Skip previous element and take current with higher multiplier
        skip[i] = dp[i-2] + (i+1) * a[i];
        dp[i] = max(dp[i-1] + (i+1 - (i - (i-1))) * a[i], skip[i]);
    }

    cout << max(dp[n-1], skip[n-1]) << endl;

    return 0;
}