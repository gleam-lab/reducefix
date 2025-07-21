#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
int n, x;

int a[N], p[N], b[N], q[N];

bool check(int mid) {
    int cost[N];
    for (int i = 1; i <= n; ++i) {
        cost[i] = LLONG_MAX;
        // Try all possible number of type A attacks
        for (int j = 0; j <= b[i]; ++j) {
            int atkA = j * a[i];
            int left = mid - atkA;
            if (left <= 0) {
                // If A alone can kill the monster
                cost[i] = min(cost[i], j * p[i]);
                continue;
            }
            int needB = (left + b[i] - 1) / b[i];
            cost[i] = min(cost[i], j * p[i] + needB * q[i]);
        }

        // Try all possible number of type B attacks
        for (int j = 0; j <= a[i]; ++j) {
            int atkB = j * b[i];
            int left = mid - atkB;
            if (left <= 0) {
                // If B alone can kill the monster
                cost[i] = min(cost[i], j * q[i]);
                continue;
            }
            int needA = (left + a[i] - 1) / a[i];
            cost[i] = min(cost[i], j * q[i] + needA * p[i]);
        }
    }

    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total += cost[i];
        if (total > x) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e18;
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