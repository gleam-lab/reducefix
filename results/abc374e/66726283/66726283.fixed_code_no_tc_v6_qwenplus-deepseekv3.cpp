#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        int min_cost = LLONG_MAX;
        // Try all possible combinations of a and b operations
        for (int j = 0; j <= mid / a[i] + 1; j++) {
            int remaining = max(0LL, mid - j * a[i]);
            int k = (remaining + b[i] - 1) / b[i];
            if (j + k > mid) continue;  // Total operations can't exceed mid
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        for (int j = 0; j <= mid / b[i] + 1; j++) {
            int remaining = max(0LL, mid - j * b[i]);
            int k = (remaining + a[i] - 1) / a[i];
            if (j + k > mid) continue;  // Total operations can't exceed mid
            min_cost = min(min_cost, j * q[i] + k * p[i]);
        }
        if (min_cost == LLONG_MAX) return false;
        total_cost += min_cost;
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e18, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}