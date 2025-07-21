#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate cost per unit for both options
        ld costA = (ld)p[i] / a[i];
        ld costB = (ld)q[i] / b[i];

        if (costA < costB) {
            // Prefer using A first since it's cheaper per unit
            int useA = min(mid / a[i], (int)1e18); // prevent overflow
            total_cost += useA * p[i];
            mid -= useA * a[i];
            total_cost += (ld)mid * costB;
        } else {
            // Prefer using B first
            int useB = min(mid / b[i], (int)1e18); // prevent overflow
            total_cost += useB * q[i];
            mid -= useB * b[i];
            total_cost += (ld)mid * costA;
        }
    }

    return total_cost <= x + 1e-8; // floating point tolerance
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left << "\n";

    return 0;
}