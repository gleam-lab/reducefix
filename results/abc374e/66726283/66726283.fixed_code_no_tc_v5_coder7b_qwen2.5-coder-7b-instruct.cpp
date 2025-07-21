#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;

int n, x;
int a[N], b[N], p[N], q[N];
int c[N];

bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        c[i] = INT_MAX;
        for (int j = 0; j <= mid / a[i]; j++) {
            c[i] = min(c[i], j * p[i] + max(0LL, mid - j * a[i]) * q[i] / b[i]);
        }
        for (int j = 0; j <= mid / b[i]; j++) {
            c[i] = min(c[i], j * q[i] + max(0LL, mid - j * b[i]) * p[i] / a[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += c[i];
    }
    if (ans > x) return false;
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

    int l = 0, r = x;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << endl;
    return 0;
}