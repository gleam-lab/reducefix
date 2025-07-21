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
    vector<ll> dp_consec(n, 0); // tracks consecutive defeats

    dp[0] = a[0];
    dp_consec[0] = a[0];
    
    dp[1] = a[0] + 2 * a[1];
    dp_consec[1] = 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // Option 1: Start new sequence (multiplier = 1)
        ll option1 = dp[i-1] + a[i];
        // Option 2: Continue consecutive sequence (multiplier +1)
        ll option2 = dp_consec[i-1] + (i+1) * a[i];
        // Option 3: Skip one and start new sequence
        ll option3 = (i >= 2) ? dp[i-2] + 2 * a[i] : 0;
        
        dp_consec[i] = max(option2, option3);
        dp[i] = max({option1, option2, option3});
    }
    cout << dp[n-1] << endl;

    return 0;
}