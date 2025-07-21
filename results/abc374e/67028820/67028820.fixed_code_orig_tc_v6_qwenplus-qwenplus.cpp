#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate cost per unit for each option
        ld costA = (ld)p[i] / a[i];
        ld costB = (ld)q[i] / b[i];

        if (costA < costB) {
            // Prefer using more of A
            int countA = mid / a[i];
            int remaining = mid % a[i];
            total_cost += countA * p[i];
            total_cost += remaining * costB;
        } else {
            // Prefer using more of B
            int countB = mid / b[i];
            int remaining = mid % b[i];
            total_cost += countB * q[i];
            total_cost += remaining * costA;
        }
    }

    return total_cost <= x + 1e-9; // Tolerance for floating point precision
}

signed main() {
    cin >> n >> x;
    a.resize(n); p.resize(n); b.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int left = 0, right = 2e14; // Extended upper bound to be safe
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}