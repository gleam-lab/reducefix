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

    // Early returns for small cases
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp(n, 0); // dp[i] = max experience up to monster i
    vector<ll> bonus(n, 0); // bonus[i] = additional multiplier gained at i

    dp[0] = a[0];
    dp[1] = a[0] + 2 * a[1];
    bonus[0] = 0;
    bonus[1] = 1;

    for (int i = 2; i < n; ++i) {
        // Option 1: Take previous monster (bonus +1)
        ll option1 = dp[i-1] + (1 + bonus[i-1]) * a[i];
        // Option 2: Skip previous monster (bonus resets to 1)
        ll option2 = dp[i-2] + 2 * a[i];
        
        if (option1 > option2) {
            dp[i] = option1;
            bonus[i] = bonus[i-1] + 1;
        } else {
            dp[i] = option2;
            bonus[i] = 1;
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}