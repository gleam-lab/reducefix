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
        
        // Calculate cost if we prioritize a[i] first
        int use_a = remaining / a[i];
        cost += use_a * p[i];
        remaining -= use_a * a[i];
        if (remaining > 0) {
            cost += (remaining + b[i] - 1) / b[i] * q[i];
        }
        
        // Calculate cost if we prioritize b[i] first
        int alternative_cost = 0;
        remaining = mid;
        int use_b = remaining / b[i];
        alternative_cost += use_b * q[i];
        remaining -= use_b * b[i];
        if (remaining > 0) {
            alternative_cost += (remaining + a[i] - 1) / a[i] * p[i];
        }
        
        // Choose the cheaper option
        total_cost += min(cost, alternative_cost);
        
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
        int mid = left + (right - left + 1) / 2;
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;
    return 0;
}