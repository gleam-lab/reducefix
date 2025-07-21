#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (int(i) = (n) - 1; (i) >= 0; --(i))

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

    vector<ll> dp(n);
    vector<ll> skip1(n); // max experience if we skipped 1 monster before current
    vector<ll> skip2(n); // max experience if we skipped 2 monsters before current

    dp[0] = a[0];
    skip1[0] = 0; // can't skip first monster
    skip2[0] = 0; // can't skip first monster

    if (n > 1) {
        dp[1] = dp[0] + a[1];
        skip1[1] = 2 * a[1]; // we skipped the first monster
        skip2[1] = 0; // can't have skipped 2 monsters before second monster
    }

    for (int i = 2; i < n; ++i) {
        // Current monster can be:
        // 1. Defeated normally (multiplier 1)
        //    - Coming from previous normal defeat or skip1
        // 2. Defeated after skipping 1 (multiplier 2)
        //    - Coming from skip1 or skip2 of previous monster
        // 3. Defeated after skipping 2 (multiplier 3)
        //    - Coming from skip2 of previous monster
        
        dp[i] = max(dp[i-1], skip1[i-1]) + a[i];
        skip1[i] = max(skip1[i-1], skip2[i-1]) + 2 * a[i];
        if (i >= 2) {
            skip2[i] = dp[i-2] + 3 * a[i];
        }
        if (i >= 3) {
            skip2[i] = max(skip2[i], skip1[i-2] + 3 * a[i]);
        }
    }

    cout << max({dp[n-1], skip1[n-1], skip2[n-1]}) << endl;

    return 0;
}