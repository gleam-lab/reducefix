#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(ld mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        if (s < t) {
            ld x = mid / a[i];
            total_cost += x * p[i];
            mid -= x * a[i];
            total_cost += mid * t;
        } else {
            ld x = mid / b[i];
            total_cost += x * q[i];
            mid -= x * b[i];
            total_cost += mid * s;
        }
    }

    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ld left = 0, right = 1e18;
    while (right - left > 1e-9) {
        ld mid = (left + right) / 2;

        if (canMake(mid)) left = mid;
        else right = mid;
    }

    printf("%.0Lf\n", left);

    return 0;
}