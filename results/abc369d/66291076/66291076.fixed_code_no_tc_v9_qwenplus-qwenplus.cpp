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

    // dp_odd[i]: max exp if we kill odd number of monsters up to i
    // dp_even[i]: max exp if we kill even number of monsters up to i
    vector<ll> dp_odd(n, 0), dp_even(n, 0);

    // Base cases
    dp_odd[0] = a[0];      // Only one monster, odd count
    dp_even[0] = 0;        // Can't have even count with one monster

    for (int i = 1; i < n; ++i) {
        // For i-th monster, compute max if we end with odd or even count
        dp_odd[i] = max(dp_even[i-1] + a[i], dp_odd[i-1]); // Kill current or not
        dp_even[i] = max(dp_odd[i-1] + 2 * a[i], dp_even[i-1]); // Kill current with even count or skip
    }

    cout << dp_even[n-1] << endl; // Need to end with even number of monsters killed
    return 0;
}