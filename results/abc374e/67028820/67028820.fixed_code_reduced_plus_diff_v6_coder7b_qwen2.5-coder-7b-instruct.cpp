#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(ld mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld cost_a = mid / a[i];
        ld cost_b = mid / b[i];
        ld cost_p = cost_a * p[i];
        ld cost_q = cost_b * q[i];
        
        if (cost_p < cost_q) {
            total_cost += cost_p;
        } else {
            total_cost += cost_q;
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
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(0) << left << endl;

    return 0;
}