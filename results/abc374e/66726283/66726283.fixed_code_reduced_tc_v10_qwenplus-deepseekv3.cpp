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
        // Try all possible combinations of a[i] and b[i] bundles
        for (int j = 0; j <= (mid + a[i] - 1) / a[i]; j++) {
            int remaining = mid - j * a[i];
            if (remaining < 0) continue;
            int k = (remaining + b[i] - 1) / b[i];
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        for (int k = 0; k <= (mid + b[i] - 1) / b[i]; k++) {
            int remaining = mid - k * b[i];
            if (remaining < 0) continue;
            int j = (remaining + a[i] - 1) / a[i];
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
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
    int l = 0, r = 1e18;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}