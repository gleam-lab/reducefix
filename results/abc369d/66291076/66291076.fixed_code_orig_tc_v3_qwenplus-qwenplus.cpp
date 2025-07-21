#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; (i) < (n); ++(i))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }

    // dp_odd[i]: max exp ending at i with odd count of uses
    // dp_even[i]: max exp ending at i with even count of uses
    vector<ll> dp_odd(n), dp_even(n);

    dp_odd[0] = a[0];
    dp_even[0] = 0;

    dp_odd[1] = a[1]; // previous was even (0 uses)
    dp_even[1] = a[0] + 2 * a[1]; // previous was odd (1 use)

    for (int i = 2; i < n; ++i) {
        // Transition from even to current: we can use current once
        dp_odd[i] = max(dp_even[i - 1] + a[i], dp_odd[i - 2] + 2 * a[i]);
        // Transition from odd to current: we can use current twice
        dp_even[i] = max(dp_odd[i - 1] + 2 * a[i], dp_even[i - 2] + a[i]);
    }

    cout << max(dp_odd[n - 1], dp_even[n - 1]) << '\n';

    return 0;
}