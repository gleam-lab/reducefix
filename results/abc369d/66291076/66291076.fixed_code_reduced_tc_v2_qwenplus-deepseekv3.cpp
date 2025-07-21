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

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<ll> dp_odd(n, 0); // dp_odd[i] = max experience when i-th monster is defeated odd times
    vector<ll> dp_even(n, 0); // dp_even[i] = max experience when i-th monster is defeated even times

    dp_odd[0] = a[0];
    dp_even[0] = 0;
    dp_odd[1] = a[1];
    dp_even[1] = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        dp_odd[i] = max(
            dp_odd[i - 1] + a[i], // previous was odd, current becomes even (but we track odd)
            dp_even[i - 1] + a[i] // previous was even, current becomes odd
        );
        dp_even[i] = max(
            dp_even[i - 1] + 2 * a[i], // previous was even, current becomes odd (but track even)
            dp_odd[i - 1] + 2 * a[i] // previous was odd, current becomes even
        );
    }
    cout << max(dp_odd[n - 1], dp_even[n - 1]) << endl;

    return 0;
}