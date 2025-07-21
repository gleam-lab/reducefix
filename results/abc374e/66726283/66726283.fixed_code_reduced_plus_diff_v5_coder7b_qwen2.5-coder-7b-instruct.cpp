#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    memset(c, 0x3f, sizeof(c));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= b[i]; j++) {
            if (j * p[i] + q[i] * ((mid - j * a[i]) / b[i]) < c[i]) {
                c[i] = j * p[i] + q[i] * ((mid - j * a[i]) / b[i]);
            }
        }
        for (int j = 0; j <= b[i]; j++) {
            if (j * q[i] + p[i] * ((mid - j * b[i]) / a[i]) < c[i]) {
                c[i] = j * q[i] + p[i] * ((mid - j * b[i]) / a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += c[i];
    }
    return ans <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l - 1 << endl;
    return 0;
}