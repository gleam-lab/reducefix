#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(ld mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld cost_a = (mid / a[i]) * p[i];
        ld cost_b = (mid / b[i]) * q[i];
        total_cost += min(cost_a, cost_b);
    }

    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ld left = 0, right = 1e10;
    while (right - left > 1e-6) {
        ld mid = (left + right) / 2;

        if (canMake(mid)) left = mid;
        else right = mid;
    }

    cout << fixed << setprecision(6) << left << endl;

    return 0;
}