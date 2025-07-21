#include <bits/stdc++.h>
using namespace std;

long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0;
    r = 1000000000000000000LL; // Adjusted to handle large values
    ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        bool feasible = true;
        for (int i = 1; i <= n; i++) {
            minn = LLONG_MAX;
            long long max_j = min(mid / a[i], b[i]);
            for (long long j = 0; j <= max_j; j++) {
                long long rem = mid - j * a[i];
                if (rem <= 0) {
                    minn = min(minn, j * p[i]);
                } else {
                    long long k = (rem + b[i] - 1) / b[i]; // Ceiling division
                    if (k <= q[i]) {
                        minn = min(minn, j * p[i] + k * q[i]);
                    }
                }
            }
            max_j = min(mid / b[i], a[i]);
            for (long long j = 0; j <= max_j; j++) {
                long long rem = mid - j * b[i];
                if (rem <= 0) {
                    minn = min(minn, j * q[i]);
                } else {
                    long long k = (rem + a[i] - 1) / a[i]; // Ceiling division
                    if (k <= p[i]) {
                        minn = min(minn, j * q[i] + k * p[i]);
                    }
                }
            }
            if (minn == LLONG_MAX) {
                feasible = false;
                break;
            }
            sum += minn;
            if (sum > x) {
                feasible = false;
                break;
            }
        }
        if (feasible && sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}