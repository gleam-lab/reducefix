#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

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

    vector<ll> dp(n, 0);
    dp[0] = a[0];
    dp[1] = max(a[0] + 2 * a[1], a[1] + 2 * a[0]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(max(dp[i - 1], dp[i - 2] + a[i]), max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i] + 2 * a[i - 1]));
    }
    cout << dp[n - 1] << endl;

    return 0;
}