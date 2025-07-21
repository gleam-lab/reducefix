#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_p = (remaining / a[i]) * p[i];
        remaining %= a[i];
        cost_p += (remaining * q[i] + b[i] - 1) / b[i]; // ceil(remaining * q[i] / b[i])

        int cost_q = (remaining / b[i]) * q[i];
        remaining %= b[i];
        cost_q += (remaining * p[i] + a[i] - 1) / a[i]; // ceil(remaining * p[i] / a[i])

        total_cost += min(cost_p, cost_q);
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18; // Sufficiently large upper bound
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