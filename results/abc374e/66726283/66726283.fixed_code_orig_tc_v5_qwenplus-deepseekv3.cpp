#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        c[i] = LLONG_MAX;
        for (int j = 0; j <= mid / a[i] + 1; j++) {
            int remaining = mid - j * a[i];
            if (remaining < 0) continue;
            int k = (remaining + b[i] - 1) / b[i];
            c[i] = min(c[i], j * p[i] + k * q[i]);
        }
        for (int j = 0; j <= mid / b[i] + 1; j++) {
            int remaining = mid - j * b[i];
            if (remaining < 0) continue;
            int k = (remaining + a[i] - 1) / a[i];
            c[i] = min(c[i], j * q[i] + k * p[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += c[i];
        if (ans > x) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
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