#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        int cost1 = p[i] * (temp / a[i]);
        temp %= a[i];
        cost1 += (temp * q[i] + b[i] - 1) / b[i]; // Ceiling division for remaining items
        
        int cost2 = q[i] * (temp / b[i]);
        temp = mid % b[i];
        cost2 += (temp * p[i] + a[i] - 1) / a[i]; // Ceiling division for remaining items
        
        total_cost += min(cost1, cost2);
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
        int mid = (left + right + 1) >> 1;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}