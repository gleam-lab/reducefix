#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = (ld)p[i] / a[i]; // cost per unit time for a[i]
        ld t = (ld)q[i] / b[i]; // cost per unit time for b[i]

        // Determine the optimal combination
        if (s < t) {
            // Buy as many a[i] as possible, then fill remaining with s
            int full_units = temp / a[i];
            total_cost += full_units * p[i];
            temp -= full_units * a[i];
            total_cost += temp * s;
        } else {
            // Buy as many b[i] as possible, then fill remaining with t
            int full_units = temp / b[i];
            total_cost += full_units * q[i];
            temp -= full_units * b[i];
            total_cost += temp * t;
        }
    }

    return total_cost <= x + 1e-9; // Account for floating point precision
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}