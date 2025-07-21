#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_a = (remaining / a[i]) * p[i];
        int cost_b = (remaining / b[i]) * q[i];
        
        // Calculate the cost for full packages
        int full_cost = min(cost_a, cost_b);
        remaining -= full_cost == cost_a ? (remaining / a[i]) * a[i] : (remaining / b[i]) * b[i];
        
        // Calculate the cost for remaining units
        int rem_cost_a = (remaining > 0) ? p[i] : 0;
        int rem_cost_b = (remaining > 0) ? q[i] : 0;
        int rem_cost = min(rem_cost_a, rem_cost_b);
        
        total_cost += full_cost + rem_cost;
        
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canMake(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}