#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];
        
        int max_a = mid / a[i];
        int max_b = mid / b[i];
        
        ld cost_a = max_a * p[i];
        ld cost_b = max_b * q[i];
        
        if (s <= t) {
            total_cost += cost_a;
            int remaining = mid - max_a * a[i];
            total_cost += remaining * t;
        } else {
            total_cost += cost_b;
            int remaining = mid - max_b * b[i];
            total_cost += remaining * s;
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
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}