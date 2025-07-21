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
    }

    // dp_odd[i]: max exp if we defeat odd number of monsters up to i-th
    // dp_even[i]: max exp if we defeat even number of monsters up to i-th
    vector<ll> dp_odd(n, 0), dp_even(n, 0);

    // Base cases
    dp_odd[0] = a[0];
    dp_even[0] = 0;

    for (int i = 1; i < n; ++i) {
        // If we take a[i] as odd count (switch from even)
        dp_odd[i] = dp_even[i-1] + a[i];
        // If we take a[i] as even count (switch from odd and double it)
        dp_even[i] = dp_odd[i-1] + 2 * a[i];
    }

    cout << max(dp_odd[n-1], dp_even[n-1]) << endl;

    return 0;
}