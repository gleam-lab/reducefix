#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate cost for this item to make 'mid' units
        ld cost_per_a = (ld)p[i] / a[i];
        ld cost_per_b = (ld)q[i] / b[i];

        if (cost_per_a < cost_per_b) {
            // Prefer buying full sets of type b first (cheaper), then fill with a
            int num_full_b = mid / b[i];
            total_cost += num_full_b * q[i];
            int remaining = mid - num_full_b * b[i];
            total_cost += remaining * p[i] / (ld)a[i];
        } else {
            // Prefer buying full sets of type a first (cheaper), then fill with b
            int num_full_a = mid / a[i];
            total_cost += num_full_a * p[i];
            int remaining = mid - num_full_a * a[i];
            total_cost += remaining * q[i] / (ld)b[i];
        }
    }

    return total_cost <= x + 1e-8; // Allow small floating point error
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); p.resize(n); b.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int left = 0, right = 2e9; // More reasonable upper bound
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left;

    return 0;
}