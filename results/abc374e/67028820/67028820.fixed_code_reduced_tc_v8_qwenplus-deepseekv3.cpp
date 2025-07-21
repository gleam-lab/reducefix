#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_a = (remaining / a[i]) * p[i];
        int cost_b = (remaining / b[i]) * q[i];
        
        if (cost_a < cost_b) {
            total_cost += cost_a;
            remaining %= a[i];
            total_cost += (remaining * q[i] + b[i] - 1) / b[i]; // ceil(remaining * q[i] / b[i])
        } else {
            total_cost += cost_b;
            remaining %= b[i];
            total_cost += (remaining * p[i] + a[i] - 1) / a[i]; // ceil(remaining * p[i] / a[i])
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
        int mid = left + (right - left + 1) / 2;
        
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}