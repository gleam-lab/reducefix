#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(ld mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld cost_a = p[i] / (ld)a[i];
        ld cost_b = q[i] / (ld)b[i];

        // Calculate the number of items to buy from each type
        ld num_a = min(mid / a[i], mid / b[i]);
        ld remaining = mid - num_a * a[i];

        // Add the cost of the items bought from each type
        total_cost += num_a * p[i];
        total_cost += remaining * max(cost_a, cost_b);

        // If we have enough budget left after buying from both types
        if (remaining >= a[i]) {
            num_a += remaining / a[i];
            remaining = 0;
        } else {
            break;
        }
    }

    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ld left = 0, right = 1e18; // Increase the upper bound since the cost can be large
    while (right - left > 1e-9) {
        ld mid = (left + right) / 2;

        if (canMake(mid)) left = mid;
        else right = mid;
    }

    cout << fixed << setprecision(6) << left << endl;

    return 0;
}