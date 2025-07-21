#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // Early return for small cases
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << max(a[0] + 2 * a[1], 2 * a[0] + a[1]) << endl;
        return 0;
    }

    // dp_odd[i]: max exp if we have killed odd number of monsters up to i
    // dp_even[i]: max exp if we have killed even number of monsters up to i
    vector<ll> dp_odd(n, 0), dp_even(n, 0);
    dp_odd[0] = a[0];
    dp_even[0] = 0;

    for (int i = 1; i < n; ++i) {
        dp_odd[i] = max(dp_even[i-1] + a[i], dp_odd[i-1]); // kill or skip
        dp_even[i] = max(dp_odd[i-1] + 2*a[i], dp_even[i-1]); // kill or skip
    }

    cout << dp_even[n-1] << endl; // need to kill even number overall

    return 0;
}