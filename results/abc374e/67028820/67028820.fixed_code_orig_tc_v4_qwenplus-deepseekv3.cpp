#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost1 = 0, cost2 = 0;
        
        // Option 1: Use a[i] first, then b[i]
        int full_a = remaining / a[i];
        cost1 += full_a * p[i];
        remaining -= full_a * a[i];
        cost1 += (remaining * q[i] + b[i] - 1) / b[i]; // Ceiling division
        
        remaining = mid;
        
        // Option 2: Use b[i] first, then a[i]
        int full_b = remaining / b[i];
        cost2 += full_b * q[i];
        remaining -= full_b * b[i];
        cost2 += (remaining * p[i] + a[i] - 1) / a[i]; // Ceiling division
        
        total_cost += min(cost1, cost2);
        
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