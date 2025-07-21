#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // We need to make 'mid' units of product using either recipe A or B
        ld costA = (ld)p[i] / a[i]; // cost per unit using recipe A
        ld costB = (ld)q[i] / b[i]; // cost per unit using recipe B

        if (costA < costB) {
            // Prefer recipe A as it's cheaper
            int num_full_A = mid / a[i];
            int remaining = mid % a[i];
            total_cost += num_full_A * p[i];
            total_cost += remaining * costB; // Use B for leftover since A can't be used partially
        } else {
            // Prefer recipe B as it's cheaper
            int num_full_B = mid / b[i];
            int remaining = mid % b[i];
            total_cost += num_full_B * q[i];
            total_cost += remaining * costA; // Use A for leftover since B can't be used partially
        }
    }

    return total_cost <= x + 1e-8; // Tolerance for floating point comparison
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); p.resize(n); b.resize(n); q.resize(n);
    for (int i = 0; i < n; ++i) {
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

    cout << left << "\n";

    return 0;
}