#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        c[i] = INT_MAX;
        for (int j = 0; j <= b[i]; j++) {
            if (j * p[i] + q[i] * ((mid - j * a[i]) / a[i] + (mid - j * a[i]) % a[i] != 0) <= mid) {
                c[i] = min(c[i], j * p[i] + q[i] * ((mid - j * a[i]) / a[i] + (mid - j * a[i]) % a[i] != 0));
            }
            if (j * q[i] + p[i] * ((mid - j * b[i]) / b[i] + (mid - j * b[i]) % b[i] != 0) <= mid) {
                c[i] = min(c[i], j * q[i] + p[i] * ((mid - j * b[i]) / b[i] + (mid - j * b[i]) % b[i] != 0));
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
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}