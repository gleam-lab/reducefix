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
        // Try all possible number of type A attacks
        for (int j = 0; j <= b[i]; ++j) {
            int atkA = j;
            int needB = max(0LL, (mid - atkA * a[i] + b[i] - 1) / b[i]);
            min_cost = min(min_cost, atkA * p[i] + needB * q[i]);
        }
        for (int j = 0; j <= a[i]; ++j) {
            int atkB = j;
            int needA = max(0LL, (mid - atkB * b[i] + a[i] - 1) / a[i]);
            min_cost = min(min_cost, needA * p[i] + atkB * q[i]);
        }
        if (cost > x) return false;
        cost += min_cost;
    }
    return cost <= x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    int max_health = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e5; // Adjust range safely based on constraints
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