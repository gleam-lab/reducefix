#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n;
int x;
int a[N], b[N], p[N], q[N];

int check(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        int cost1 = 0, cost2 = 0;
        for (int j = 0; j <= b[i]; j++) {
            cost1 = min(cost1, j * p[i] + q[i] * (mid - j * a[i] + b[i] - 1) / b[i]);
        }
        for (int j = 0; j <= a[i]; j++) {
            cost2 = min(cost2, j * q[i] + p[i] * (mid - j * b[i] + a[i] - 1) / a[i]);
        }
        total_cost += min(cost1, cost2);
    }
    return total_cost;
}

int solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min(a[i] * q[i], b[i] * p[i]);
    }
    int l = 1, r = 1e18;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid) <= x - ans) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        cout << solve() << '\n';
    }
    return 0;
}