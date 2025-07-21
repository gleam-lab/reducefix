#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate how much we can make using A and B patterns
        ld costA = (ld)p[i] / a[i];  // cost per unit using A
        ld costB = (ld)q[i] / b[i];  // cost per unit using B

        if (costA < costB) {
            // Prefer buying in A bundles first (cheaper per unit)
            int num_full_A = mid / a[i];
            total_cost += num_full_A * p[i];
            int remaining = mid - num_full_A * a[i];
            total_cost += remaining * costA;
        } else {
            // Prefer buying in B bundles first
            int num_full_B = mid / b[i];
            total_cost += num_full_B * q[i];
            int remaining = mid - num_full_B * b[i];
            total_cost += remaining * costB;
        }
    }

    return total_cost <= x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); p.resize(n); b.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << '\n';

    return 0;
}