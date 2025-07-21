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

        if (costA <= costB) {
            // Prefer buying as much as possible from A first
            int maxFromA = mid / a[i];
            int remaining = mid % a[i];
            total_cost += (ld)maxFromA * p[i] + (ld)remaining * costB;
        } else {
            // Prefer buying as much as possible from B first
            int maxFromB = mid / b[i];
            int remaining = mid % b[i];
            total_cost += (ld)maxFromB * q[i] + (ld)remaining * costA;
        }
    }

    return total_cost <= x;
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

    cout << left;

    return 0;
}