#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = LLONG_MAX;
        // Iterate possible counts of buying a items (k) and b items (l) such that k*a[i] + l*b[i] >= mid
        // To minimize cost, we can consider k and l such that k*a[i] + l*b[i] >= mid, and k + l is minimized
        // Alternatively, find the minimal cost combination to cover at least mid items
        for (int k = 0; k <= (mid + a[i] - 1) / a[i]; ++k) {
            int remaining = max(mid - k * a[i], 0LL);
            int l = (remaining + b[i] - 1) / b[i];
            min_cost = min(min_cost, k * p[i] + l * q[i]);
        }
        for (int l = 0; l <= (mid + b[i] - 1) / b[i]; ++l) {
            int remaining = max(mid - l * b[i], 0LL);
            int k = (remaining + a[i] - 1) / a[i];
            min_cost = min(min_cost, k * p[i] + l * q[i]);
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