#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    // Early return for small cases
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
    
    // This represents the maximum when we have an odd number of kills up to i-1
    ll max_odd = a[0];
    // This represents the maximum when we have an even number of kills up to i-1
    ll max_even = 0;

    for (int i = 2; i < n; ++i) {
        // Current maximum when ending with even kills
        ll current_even = max_even + a[i];
        // Current maximum when ending with odd kills
        ll current_odd = max_odd + 2 * a[i];
        
        dp[i] = max(current_even, current_odd);
        
        // Update the trackers for next iteration
        ll new_max_odd = max(max_odd, dp[i-1]);
        ll new_max_even = max(max_even, dp[i-1] + a[i]);
        
        max_odd = new_max_odd;
        max_even = new_max_even;
    }
    cout << dp[n-1] << endl;

    return 0;
}