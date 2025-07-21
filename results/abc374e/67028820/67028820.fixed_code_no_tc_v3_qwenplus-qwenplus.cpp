#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate how much we can take from each type optimally
        ld costA = (ld)p[i] / a[i];  // cost per unit from option A
        ld costB = (ld)q[i] / b[i];  // cost per unit from option B

        if (costA < costB) {
            // Prefer buying full packs of A first, then use remaining greedily
            int count = mid / a[i];
            total_cost += count * p[i];
            int remaining = mid - count * a[i];
            total_cost += remaining * costA;
        } else {
            // Prefer buying full packs of B first, then use remaining greedily
            int count = mid / b[i];
            total_cost += count * q[i];
            int remaining = mid - count * b[i];
            total_cost += remaining * costB;
        }
    }

    return total_cost <= x + 1e-8;  // Allow small floating point error
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 2e9;  // Narrowed down from 1e18 to avoid overflow in calculations
    while (left < right) {
        int mid = (left + right + 1) / 2;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left << '\n';

    return 0;
}