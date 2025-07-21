#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = LLONG_MAX;
        // Iterate possible j (number of a[i] tasks) up to the maximum possible for mid
        int max_j = min(mid / a[i], b[i]);
        for (int j = 0; j <= max_j; ++j) {
            int remaining = mid - j * a[i];
            if (remaining < 0) continue;
            int k = (remaining + b[i] - 1) / b[i]; // ceiling division
            if (k < 0) k = 0;
            int cost = j * p[i] + k * q[i];
            if (cost < min_cost) min_cost = cost;
        }
        // Also consider cases where j exceeds b[i] but k is minimized
        int max_k = min(mid / b[i], a[i]);
        for (int k = 0; k <= max_k; ++k) {
            int remaining = mid - k * b[i];
            if (remaining < 0) continue;
            int j = (remaining + a[i] - 1) / a[i]; // ceiling division
            if (j < 0) j = 0;
            int cost = j * p[i] + k * q[i];
            if (cost < min_cost) min_cost = cost;
        }
        total += min_cost;
        if (total > x) return false;
    }
    return total <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = 1e18; // Sufficiently large upper bound
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