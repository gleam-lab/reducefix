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

    vector<ll> dp(n + 1, 0);
    dp[1] = a[0];
    dp[2] = a[0] + 2 * a[1];

    for (int i = 3; i <= n; ++i) {
        dp[i] = max({
            dp[i - 1] + a[i - 1],
            dp[i - 2] + 2 * a[i - 1],
            dp[i - 3] + 2 * a[i - 2] + a[i - 1]
        });
    }

    cout << dp[n] << endl;

    return 0;
}