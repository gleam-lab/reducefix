#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    rep(i, n) cin >> a[i];

    // Early return for small cases
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp_odd[i]: max exp if we kill i-th monster and total killed count is odd
    // dp_even[i]: max exp if we kill i-th monster and total killed count is even
    vector<ll> dp_odd(n, 0), dp_even(n, 0);

    // Base cases
    dp_odd[0] = a[0];     // killed 1st monster, total killed = 1 (odd)
    dp_even[0] = 0;       // not relevant, as only one monster

    // For second monster
    dp_odd[1] = a[1];                             // killed only the second monster (total 1 - odd)
    dp_even[1] = a[0] + 2 * a[1];                // killed both monsters (total 2 - even)

    for (int i = 2; i < n; ++i) {
        // If we kill this monster and previous total killed was odd -> now even
        // So use dp_odd[i-1] + 2*a[i]
        // If we skip this monster and previous total was even -> use dp_even[i-1]
        // But in our case, we assume we always kill monsters, so no skipping.

        // Transition logic:
        // To compute dp_odd[i], it means we've killed odd number of monsters UP TO i
        // Two options:
        // - We kill i-1 and i, then i-2 must have even kills: dp_even[i-2] + 2*a[i]
        // - Or we skip i-1, kill i, so i-1 had odd kills: dp_odd[i-1] + a[i]

        dp_odd[i] = max(dp_even[i-1] + a[i], dp_odd[i-1] + a[i]);
        // Correction: above line should depend on whether we include i-1 or not,
        // but logic seems flawed. Let's correct below.

        // Actually, to maintain an odd count, two ways:
        // 1. From even count at i-2 and kill i (skip i-1): dp_even[i-2] + 2*a[i]
        // 2. From odd count at i-1 and do NOT kill i: dp_odd[i-1] + a[i]
        dp_odd[i] = max(dp_even[i-2] + 2 * a[i], dp_odd[i-1] + a[i]);

        // Similarly for even:
        // 1. From odd count at i-2 and kill i: dp_odd[i-2] + 2*a[i]
        // 2. From even count at i-1 and do NOT kill i: dp_even[i-1] + a[i]
        dp_even[i] = max(dp_odd[i-2] + 2 * a[i], dp_even[i-1] + a[i]);
    }

    cout << max(dp_odd[n-1], dp_even[n-1]) << endl;

    return 0;
}