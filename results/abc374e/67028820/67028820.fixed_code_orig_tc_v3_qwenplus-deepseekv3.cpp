#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int s_cost_per_item = (p[i] + a[i] - 1) / a[i]; // ceil(p[i] / a[i])
        int t_cost_per_item = (q[i] + b[i] - 1) / b[i]; // ceil(q[i] / b[i])

        if (s_cost_per_item < t_cost_per_item) {
            int full_sets = mid / a[i];
            total_cost += full_sets * p[i];
            int remaining = mid - full_sets * a[i];
            total_cost += remaining * t_cost_per_item;
        } else {
            int full_sets = mid / b[i];
            total_cost += full_sets * q[i];
            int remaining = mid - full_sets * b[i];
            total_cost += remaining * s_cost_per_item;
        }

        if (total_cost > x) {
            return false;
        }
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