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

    // Early returns for small n
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp(n, 0); // dp[i] is the max experience up to monster i

    dp[0] = a[0];
    dp[1] = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // The optimal choice is either:
        // 1. Skip the previous monster (i-1), so current monster is defeated after i-2, hence multiplier is (1 + 1)
        // 2. Defeat the previous monster (i-1), so current multiplier is just 1
        dp[i] = max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i]);
    }
    cout << dp[n - 1] << endl;

    return 0;
}