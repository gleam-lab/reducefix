#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld s = (ld)p[i] / a[i];
        ld t = (ld)q[i] / b[i];
        
        int full_a = mid / a[i];
        ld cost_a = full_a * p[i];
        int rem_a = mid - full_a * a[i];
        ld cost_rem_a = rem_a * t;
        
        int full_b = mid / b[i];
        ld cost_b = full_b * q[i];
        int rem_b = mid - full_b * b[i];
        ld cost_rem_b = rem_b * s;
        
        total_cost += min(cost_a + cost_rem_a, cost_b + cost_rem_b);
        
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
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}