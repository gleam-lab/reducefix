#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0, r = 1e18;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        bool valid = true;
        for (int i = 1; i <= n; ++i) {
            minn = LLONG_MAX;
            // Check combinations of a[i] and b[i] to achieve mid
            for (int j = 0; j <= 100; ++j) {
                if (j * a[i] > mid) break;
                long long remaining = mid - j * a[i];
                long long k = remaining / b[i];
                if (remaining < 0) k = -1;
                if (k >= 0) {
                    minn = min(minn, j * p[i] + k * q[i]);
                }
                if (k + 1 >= 0) {
                    minn = min(minn, j * p[i] + (k + 1) * q[i]);
                }
            }
            for (int j = 0; j <= 100; ++j) {
                if (j * b[i] > mid) break;
                long long remaining = mid - j * b[i];
                long long k = remaining / a[i];
                if (remaining < 0) k = -1;
                if (k >= 0) {
                    minn = min(minn, j * q[i] + k * p[i]);
                }
                if (k + 1 >= 0) {
                    minn = min(minn, j * q[i] + (k + 1) * p[i]);
                }
            }
            if (minn == LLONG_MAX) {
                valid = false;
                break;
            }
            sum += minn;
            if (sum > x) {
                valid = false;
                break;
            }
        }
        if (valid && sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}