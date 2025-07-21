#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp_odd[i]: max exp when ending at i-th with odd number of monsters defeated
    // dp_even[i]: max exp when ending at i-th with even number of monsters defeated
    vector<ll> dp_odd(n, 0), dp_even(n, 0);

    dp_odd[0] = a[0];      // defeat first monster once
    dp_even[0] = 0;        // don't defeat first monster

    dp_odd[1] = a[1];                // defeat only second monster
    dp_even[1] = a[0] + 2 * a[1];    // defeat both monsters

    for (int i = 2; i < n; ++i) {
        // For odd count: we previously had even count and defeat current monster once
        dp_odd[i] = max(dp_even[i-1] + a[i], dp_odd[i-2] + 2 * a[i]);
        // For even count: we previously had odd count and defeat current monster twice
        dp_even[i] = max(dp_odd[i-1] + 2 * a[i], dp_even[i-2] + a[i]);
    }

    cout << max(dp_odd[n-1], dp_even[n-1]) << endl;

    return 0;
}