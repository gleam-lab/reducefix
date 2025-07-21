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
        // Try all possible number of type A potions
        for (int j = 0; j <= b[i]; ++j) {
            int needB = max(0LL, (mid - j * a[i] + b[i] - 1) / b[i]);
            if (needB > b[i]) continue; // invalid
            int total_cost = j * p[i] + needB * q[i];
            min_cost = min(min_cost, total_cost);
        }
        // Try all possible number of type B potions
        for (int j = 0; j <= a[i]; ++j) {
            int needA = max(0LL, (mid - j * b[i] + a[i] - 1) / a[i]);
            if (needA > a[i]) continue; // invalid
            int total_cost = j * q[i] + needA * p[i];
            min_cost = min(min_cost, total_cost);
        }
        if (min_cost == LLONG_MAX) return false; // Not possible to reach this monster
        cost += min_cost;
        if (cost > x) return false; // Early exit if budget exceeded
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

    int l = 0, r = 1e18; // We might not be able to defeat any monsters initially
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

    cout << ans;
    return 0;
}