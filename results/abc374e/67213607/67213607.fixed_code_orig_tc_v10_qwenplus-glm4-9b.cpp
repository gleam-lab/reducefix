#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;

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
            minn = 210000000000000000;
            for (int j = 0; j <= b[i]; j++) {
                long long dist = mid - j * a[i];
                if (dist <= 0) {
                    minn = min(minn, j * p[i]);
                } else if (dist % b[i] == 0) {
                    minn = min(minn, j * p[i] + (dist / b[i]) * q[i]);
                } else {
                    minn = min(minn, j * p[i] + (dist / b[i] + 1) * q[i]);
                }
            }
            for (int j = 0; j <= a[i]; j++) {
                long long dist = mid - j * b[i];
                if (dist <= 0) {
                    minn = min(minn, j * q[i]);
                } else if (dist % a[i] == 0) {
                    minn = min(minn, j * q[i] + (dist / a[i]) * p[i]);
                } else {
                    minn = min(minn, j * q[i] + (dist / a[i] + 1) * p[i]);
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
}