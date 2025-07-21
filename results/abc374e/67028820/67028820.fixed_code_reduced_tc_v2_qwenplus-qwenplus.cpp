#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        // We want to minimize cost: use better rate first (smaller of s and t)
        if (s < t) {
            // Use a[i] as much as possible
            int count = mid / a[i];
            total_cost += count * p[i];
            int remaining = mid % a[i];
            total_cost += remaining * t;
        } else {
            // Use b[i] as much as possible
            int count = mid / b[i];
            total_cost += count * q[i];
            int remaining = mid % b[i];
            total_cost += remaining * s;
        }
    }

    return total_cost <= x + 1e-9; // tolerance for floating point comparison
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 2e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}