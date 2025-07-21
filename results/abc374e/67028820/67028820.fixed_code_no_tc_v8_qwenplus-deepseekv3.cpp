#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_p = (p[i] + a[i] - 1) / a[i]; // ceil(p[i]/a[i])
        int cost_q = (q[i] + b[i] - 1) / b[i]; // ceil(q[i]/b[i])
        
        if (p[i] * b[i] < q[i] * a[i]) { // Compare p[i]/a[i] < q[i]/b[i] without floating point
            int full = remaining / a[i];
            total_cost += full * p[i];
            remaining -= full * a[i];
            
            int partial = (remaining + b[i] - 1) / b[i]; // ceil(remaining/b[i])
            if (partial > 0) {
                total_cost += min(partial * q[i], q[i]);
            }
        } else {
            int full = remaining / b[i];
            total_cost += full * q[i];
            remaining -= full * b[i];
            
            int partial = (remaining + a[i] - 1) / a[i]; // ceil(remaining/a[i])
            if (partial > 0) {
                total_cost += min(partial * p[i], p[i]);
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
    int answer = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canMake(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}