#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = LLONG_MAX;
        // We need to produce exactly 'mid' items using a combination of the two methods
        // Method 1: j batches of a[i], remaining (mid - j*a[i]) using b[i]
        // Method 2: j batches of b[i], remaining (mid - j*b[i]) using a[i]
        // We iterate over possible j to find the minimal cost
        int max_j1 = mid / a[i] + 2;
        for (int j = 0; j <= max_j1; ++j) {
            int remaining = mid - j * a[i];
            if (remaining < 0) continue;
            int k = (remaining + b[i] - 1) / b[i]; // ceiling(remaining / b[i])
            if (k < 0) k = 0;
            int cost = j * p[i] + k * q[i];
            if (cost < min_cost) min_cost = cost;
        }
        int max_j2 = mid / b[i] + 2;
        for (int j = 0; j <= max_j2; ++j) {
            int remaining = mid - j * b[i];
            if (remaining < 0) continue;
            int k = (remaining + a[i] - 1) / a[i]; // ceiling(remaining / a[i])
            if (k < 0) k = 0;
            int cost = j * q[i] + k * p[i];
            if (cost < min_cost) min_cost = cost;
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
    for (int i = 1; i <= n; ++i) {
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