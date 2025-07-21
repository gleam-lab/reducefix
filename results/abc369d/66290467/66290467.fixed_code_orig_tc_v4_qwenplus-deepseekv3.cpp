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

    vector<ll> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // We have three options:
        // 1. Take current a[i] as single (add a[i] to dp[i-1])
        // 2. Take current a[i] doubled (add 2*a[i] to dp[i-2])
        // 3. Take current a[i] doubled and skip two previous (add 2*a[i] to dp[i-3])
        // This accounts for patterns like high, low, high where we want to double the highs
        ll option1 = dp[i-1] + a[i];
        ll option2 = dp[i-2] + 2 * a[i];
        ll option3 = (i >= 3) ? dp[i-3] + 2 * a[i-1] + 2 * a[i] : 0;
        dp[i] = max({option1, option2, option3});
    }

    cout << dp[n-1] << endl;

    return 0;
}