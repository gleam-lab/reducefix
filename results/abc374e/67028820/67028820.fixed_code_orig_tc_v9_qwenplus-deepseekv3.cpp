#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_a_per_unit = (p[i] + a[i] - 1) / a[i];
        int cost_b_per_unit = (q[i] + b[i] - 1) / b[i];

        if (cost_a_per_unit < cost_b_per_unit) {
            int full_units = remaining / a[i];
            total_cost += full_units * p[i];
            remaining -= full_units * a[i];
            if (remaining > 0) {
                total_cost += ((remaining * q[i] + b[i] - 1) / b[i]);
            }
        } else {
            int full_units = remaining / b[i];
            total_cost += full_units * q[i];
            remaining -= full_units * b[i];
            if (remaining > 0) {
                total_cost += ((remaining * p[i] + a[i] - 1) / a[i]);
            }
        }
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}