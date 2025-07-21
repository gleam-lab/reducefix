#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        c[i] = LLONG_MAX;
        for (int j = 0; j <= b[i]; ++j) {
            if (mid - j * a[i] >= 0) {
                int remaining = mid - j * a[i];
                int k = (remaining + b[i] - 1) / b[i];
                c[i] = min(c[i], j * p[i] + k * q[i]);
            }
        }
        for (int j = 0; j <= a[i]; ++j) {
            if (mid - j * b[i] >= 0) {
                int remaining = mid - j * b[i];
                int k = (remaining + a[i] - 1) / a[i];
                c[i] = min(c[i], j * q[i] + k * p[i]);
            }
        }
        total += c[i];
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
    int l = 1, r = 1e18, ans = 0;
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