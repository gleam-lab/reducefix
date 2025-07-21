#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
long long n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN], l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0, r = 1e9;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            minn = LLONG_MAX;
            for (int j = 0; j <= b[i]; ++j) {
                if ((mid - j * a[i]) >= 0) {
                    minn = min(minn, j * p[i]);
                    if (mid - j * a[i] > 0) {
                        int k = (mid - j * a[i]) / b[i];
                        minn = min(minn, j * p[i] + (k + 1) * q[i]);
                    }
                }
            }
            for (int j = 0; j <= a[i]; ++j) {
                if ((mid - j * b[i]) >= 0) {
                    minn = min(minn, j * q[i]);
                    if (mid - j * b[i] > 0) {
                        int k = (mid - j * b[i]) / a[i];
                        minn = min(minn, j * q[i] + (k + 1) * p[i]);
                    }
                }
            }
            sum += minn;
        }
        if (sum <= x) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}