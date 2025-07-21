#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    bool possible = true;
    for (int i = 0; i < n && possible; i++) {
        int x_s = mid / a[i];
        int x_t = mid / b[i];
        ld cost_s = x_s * p[i];
        ld cost_t = x_t * q[i];
        ld needed_s = max(0LL, mid - x_s * a[i]);
        ld needed_t = max(0LL, mid - x_t * b[i]);
        ld cost_needed_s = needed_s * q[i] / b[i];
        ld cost_needed_t = needed_t * p[i] / a[i];
        total_cost += min(cost_s + cost_needed_s, cost_t + cost_needed_t);

        // Check if the current allocation allows meeting the production requirement
        if ((x_s * a[i] + needed_s) < mid || (x_t * b[i] + needed_t) < mid) {
            possible = false;
        }
    }

    return possible && (total_cost <= x);
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e9; // Adjusted the upper bound to 1e9
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}