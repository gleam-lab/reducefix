#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;

int n, x;
int a[N], b[N], p[N], q[N];
int c[N];

bool check(int mid) {
    memset(c, INT_MAX, sizeof(c));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= b[i]; ++j) {
            if (j * p[i] + q[i] * ((mid - j * a[i] + b[i] - 1) / b[i]) < c[i])
                c[i] = j * p[i] + q[i] * ((mid - j * a[i] + b[i] - 1) / b[i]);
        }
        for (int j = 0; j <= b[i]; ++j) {
            if (j * q[i] + p[i] * ((mid - j * b[i] + a[i] - 1) / a[i]) < c[i])
                c[i] = j * q[i] + p[i] * ((mid - j * b[i] + a[i] - 1) / a[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += c[i];
    }
    return ans <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 0, r = 1e18;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
    return 0;
}