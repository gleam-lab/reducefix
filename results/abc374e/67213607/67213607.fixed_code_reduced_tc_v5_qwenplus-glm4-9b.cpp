#include<bits/stdc++.h>
using namespace std;
long long n, x;
long long a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0;
    r = 1000000005;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            minn = 2LL * 1e18;
            for (int j = 0; j <= b[i]; j++) {
                if (mid - j * a[i] <= 0) {
                    minn = min(minn, j * p[i]);
                } else if ((mid - j * a[i]) % b[i] == 0) {
                    minn = min(minn, j * p[i] + ((mid - j * a[i]) / b[i]) * q[i]);
                } else {
                    minn = min(minn, j * p[i] + ((mid - j * a[i]) / b[i] + 1) * q[i]);
                }
            }
            for (int j = 0; j <= a[i]; j++) {
                if (mid - j * b[i] <= 0) {
                    minn = min(minn, j * q[i]);
                } else if ((mid - j * b[i]) % a[i] == 0) {
                    minn = min(minn, j * q[i] + ((mid - j * b[i]) / a[i]) * p[i]);
                } else {
                    minn = min(minn, j * q[i] + ((mid - j * b[i]) / a[i] + 1) * p[i]);
                }
            }
            sum += minn;
        }
        if (sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}