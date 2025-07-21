#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (int(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << (a[0] + 2 * a[1]) % MOD << endl;
        return 0;
    }

    vector<ll> dp(2, 0);
    dp[0] = a[0];
    dp[1] = (dp[0] + 2 * a[1]) % MOD;

    for (int i = 2; i < n; ++i) {
        ll next = ((dp[1] + 2 * a[i]) % MOD + (MOD - dp[0])) % MOD;
        dp[0] = dp[1];
        dp[1] = next;
    }

    cout << dp[1] << endl;

    return 0;
}