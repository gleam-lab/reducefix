#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld cost_a = p[i] / (ld)a[i];
        ld cost_b = q[i] / (ld)b[i];

        if (cost_a < cost_b) {
            int full_units = temp / a[i];
            total_cost += full_units * p[i];
            temp -= full_units * a[i];
            total_cost += temp * cost_b;
        } else {
            int full_units = temp / b[i];
            total_cost += full_units * q[i];
            temp -= full_units * b[i];
            total_cost += temp * cost_a;
        }
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