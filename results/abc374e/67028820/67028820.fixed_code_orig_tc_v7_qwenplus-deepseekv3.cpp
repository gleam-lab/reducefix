#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost = 0;
        
        int s_cost_per_unit = (p[i] + a[i] - 1) / a[i];
        int t_cost_per_unit = (q[i] + b[i] - 1) / b[i];
        
        if (s_cost_per_unit < t_cost_per_unit) {
            int full_sets = remaining / a[i];
            cost += full_sets * p[i];
            remaining -= full_sets * a[i];
            cost += remaining * s_cost_per_unit;
        } else {
            int full_sets = remaining / b[i];
            cost += full_sets * q[i];
            remaining -= full_sets * b[i];
            cost += remaining * t_cost_per_unit;
        }
        
        total_cost += cost;
        
        if (total_cost > x) {
            return false;
        }
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;

    return 0;
}