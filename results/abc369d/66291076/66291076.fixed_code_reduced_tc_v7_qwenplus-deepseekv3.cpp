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
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // dp[i][0] = max experience when count is even after defeating up to i-th monster
    // dp[i][1] = max experience when count is odd after defeating up to i-th monster
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][1] = a[0]; // count is odd (1)
    dp[1][0] = a[0] + 2 * a[1]; // count is even (2)
    dp[1][1] = a[1]; // count is odd (1)

    for (int i = 2; i < n; ++i) {
        // Option 1: Defeat current monster when previous count was odd (add 1, making it even)
        ll option1 = dp[i-1][1] + 2 * a[i];
        // Option 2: Defeat current monster when previous count was even (add 1, making it odd)
        ll option2 = dp[i-1][0] + a[i];
        // Option 3: Skip current monster (count remains as in previous step)
        ll option3_odd = dp[i-1][1];
        ll option3_even = dp[i-1][0];

        dp[i][0] = max(option1, option3_even);
        dp[i][1] = max(option2, option3_odd);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}