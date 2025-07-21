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
    }
    if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[0] + 2 * a[1];
    dp[2] = max(a[0] + 2 * a[1] + a[2], a[0] + a[1] + 2 * a[2]);

    for (int i = 3; i < n; ++i) {
        dp[i] = max(
            dp[i - 1] + a[i],               // kill only current monster (1x)
            max(
                dp[i - 2] + 2 * a[i],       // skip 1 monster (2x)
                dp[i - 3] + 2 * a[i - 1] + 3 * a[i]  // skip 2 monsters (2x + 3x)
            )
        );
    }
    cout << dp[n - 1] << endl;

    return 0;
}