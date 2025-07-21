#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int s_num = p[i];
        int s_den = a[i];
        int t_num = q[i];
        int t_den = b[i];

        if (s_num * t_den < t_num * s_den) {
            int bundles = mid / a[i];
            total_cost += bundles * p[i];
            int remaining = mid - bundles * a[i];
            if (remaining > 0) {
                int cost_per_item = (t_num + t_den - 1) / t_den;
                total_cost += remaining * cost_per_item;
            }
        } else {
            int bundles = mid / b[i];
            total_cost += bundles * q[i];
            int remaining = mid - bundles * b[i];
            if (remaining > 0) {
                int cost_per_item = (s_num + s_den - 1) / s_den;
                total_cost += remaining * cost_per_item;
            }
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