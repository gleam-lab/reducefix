#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp_prev_prev: two steps before
    // dp_prev: one step before
    // we only need to track the previous two states due to O(1) space usage
    ll dp_prev_prev_odd = a[0];
    ll dp_prev_prev_even = 0;

    ll dp_prev_odd = a[1];
    ll dp_prev_even = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        ll curr_odd = max(dp_prev_prev_odd + 2 * a[i], dp_prev_even + a[i]);
        ll curr_even = max(dp_prev_prev_even + a[i], dp_prev_odd + 2 * a[i]);

        // Update previous states for next iteration
        dp_prev_prev_odd = dp_prev_odd;
        dp_prev_prev_even = dp_prev_even;
        dp_prev_odd = curr_odd;
        dp_prev_even = curr_even;
    }

    cout << max(dp_prev_odd, dp_prev_even) << endl;

    return 0;
}