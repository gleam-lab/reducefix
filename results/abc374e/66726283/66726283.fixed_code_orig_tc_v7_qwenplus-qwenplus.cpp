#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
int n, x;
int a[N], p[N], b[N], q[N];

int c[N];

bool check(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = 1e18;
        // Try all reasonable values of j: how many times we use the first operation
        for (int j = 0; j <= mid; ++j) {
            int used = j * a[i];
            if (used > mid) break;
            int remaining = mid - used;
            int k = (remaining + b[i] - 1) / b[i]; // ceil division
            int cost = j * p[i] + k * q[i];
            min_cost = min(min_cost, cost);
        }
        total_cost += min_cost;
        if (total_cost > x) return false;
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

    int l = 0, r = 1e18;
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