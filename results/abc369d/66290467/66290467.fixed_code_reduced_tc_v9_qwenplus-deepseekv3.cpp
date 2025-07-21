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

    vector<ll> dp(n, 0); // dp[i] = max experience up to i-th monster
    vector<ll> streak(n, 0); // streak[i] = current streak length at i-th monster

    dp[0] = a[0];
    streak[0] = 1;

    dp[1] = a[0] + 2 * a[1];
    streak[1] = 2;

    for (int i = 2; i < n; ++i) {
        // Option 1: Continue the streak from i-1
        ll option1 = dp[i-1] + (streak[i-1] + 1) * a[i];
        // Option 2: Start a new streak from i-2 (skip i-1)
        ll option2 = (i >= 2 ? dp[i-2] + 2 * a[i] : 0);
        
        if (option1 >= option2) {
            dp[i] = option1;
            streak[i] = streak[i-1] + 1;
        } else {
            dp[i] = option2;
            streak[i] = 2;
        }
    }
    cout << dp[n - 1] << endl;

    return 0;
}