#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(ld mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld cost_a = p[i] / (ld)a[i], cost_b = q[i] / (ld)b[i];
        if (cost_a < cost_b) {
            total_cost += min(mid / a[i] * p[i], mid * cost_b);
        } else {
            total_cost += min(mid / b[i] * q[i], mid * cost_a);
        }
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ld left = 0, right = 1e10;
    while (right - left > 1e-9) {
        ld mid = (left + right) / 2;
        if (canMake(mid)) left = mid;
        else right = mid;
    }

    printf("%.9Lf\n", left);

    return 0;
}