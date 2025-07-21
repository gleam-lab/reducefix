#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        int full_a = temp / a[i];
        int cost_a = full_a * p[i];
        int remaining_a = temp % a[i];
        int cost_remaining_a = (remaining_a * q[i] + b[i] - 1) / b[i]; // ceiling division
        
        int full_b = temp / b[i];
        int cost_b = full_b * q[i];
        int remaining_b = temp % b[i];
        int cost_remaining_b = (remaining_b * p[i] + a[i] - 1) / a[i]; // ceiling division
        
        total_cost += min(cost_a + cost_remaining_a, cost_b + cost_remaining_b);
        
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