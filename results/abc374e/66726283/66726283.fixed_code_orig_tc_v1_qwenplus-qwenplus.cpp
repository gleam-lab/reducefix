#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], p[N], b[N], q[N];

int compute_cost(int i, int need) {
    int res = 1e18;
    // Try all possible number of type A potions
    for (int j = 0; j <= b[i]; ++j) {
        int rem = max(0LL, need - j * a[i]);
        int k = (rem + b[i] - 1) / b[i];
        k = min(k, (int)1e9); // Avoid overflow
        if (k > p[i]) continue; // Not enough money for this option
        res = min(res, j * p[i] + k * q[i]);
    }

    // Try all possible number of type B potions
    for (int j = 0; j <= a[i]; ++j) {
        int rem = max(0LL, need - j * b[i]);
        int k = (rem + a[i] - 1) / a[i];
        k = min(k, (int)1e9); // Avoid overflow
        if (k > q[i]) continue; // Not enough money for this option
        res = min(res, j * q[i] + k * p[i]);
    }
    return res;
}

bool check(int mid) {
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        int cost = compute_cost(i, mid);
        if (cost > x) return false;
        total += cost;
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

    int l = 0, r = 1e9;
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