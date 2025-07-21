#include <bits/stdc++.h>
using namespace std;

#define ll __int128

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> x(n + 1), p(n + 1), a(n + 1);

    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];

    // Compute prefix sums
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + p[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        // Find the smallest index j such that x[j] >= l
        auto it_l = lower_bound(x.begin(), x.end(), l);
        int l1 = it_l - x.begin();

        // Find the largest index j such that x[j] <= r
        auto it_r = upper_bound(x.begin(), x.end(), r);
        int r2 = it_r - x.begin() - 1;

        // Adjust indices if they go out of bounds
        if (l1 > n) l1 = n;
        if (r2 < 1) r2 = 1;

        // Calculate the result
        ll result = a[r2] - a[l1 - 1];
        cout << result << endl;
    }

    return 0;
}