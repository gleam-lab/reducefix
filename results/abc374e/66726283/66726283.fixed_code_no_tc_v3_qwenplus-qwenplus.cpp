#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int cost = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = LLONG_MAX;
        // Try all possible number of type A attacks, and compute corresponding B attacks needed
        for (int j = 0; j <= b[i]; ++j) {
            int damage_from_A = j * a[i];
            int remaining = max(0LL, mid - damage_from_A);
            int k = (remaining + b[i] - 1) / b[i]; // ceil division
            if (k > q[i]) continue; // Invalid combination
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        for (int k = 0; k <= q[i]; ++k) {
            int damage_from_B = k * b[i];
            int remaining = max(0LL, mid - damage_from_B);
            int j = (remaining + a[i] - 1) / a[i]; // ceil division
            if (j > p[i]) continue; // Invalid combination
            min_cost = min(min_cost, j * q[i] + k * p[i]);
        }
        if (min_cost == LLONG_MAX) return false;
        cost += min_cost;
        if (cost > x) return false;
    }
    return cost <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e14; // Large enough upper bound
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}