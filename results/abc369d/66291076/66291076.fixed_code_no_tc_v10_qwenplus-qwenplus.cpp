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
    dp_odd[0] = a[0];     // Only one monster, odd count
    dp_even[0] = 0;       // Can't have even count with one monster

    for (int i = 1; i < n; ++i) {
        // For odd count up to i
        dp_odd[i] = max(dp_even[i-1] + a[i],         // Kill this one, previous was even
                        (i >= 2 ? dp_odd[i-2] + 2*a[i] : 0)); // Skip previous, kill this and one before
        
        // For even count up to i
        dp_even[i] = max(dp_odd[i-1] + 2*a[i],       // Kill this one, previous was odd
                         (i >= 2 ? dp_even[i-2] + a[i] : 0)); // Skip previous, even before
    }

    cout << max(dp_odd[n-1], dp_even[n-1]) << endl;
    return 0;
}