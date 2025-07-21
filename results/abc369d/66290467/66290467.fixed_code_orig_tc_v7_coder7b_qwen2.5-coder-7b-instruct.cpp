#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (int(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    // Edge case: If there is only one monster, we just take it.
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // Edge case: If there are two monsters, we take both.
    if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // Initialize DP array
    vector<ll> dp(n, 0);
    dp[0] = a[0]; // We can only take the first monster
    dp[1] = max(a[0], a[1]); // Take the maximum between the first and second monster

    // Fill the DP array
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}