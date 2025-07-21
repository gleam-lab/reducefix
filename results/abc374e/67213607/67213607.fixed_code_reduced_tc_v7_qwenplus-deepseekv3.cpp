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
            minn = LLONG_MAX;
            // Iterate through possible combinations of a[i] and b[i]
            for (int j = 0; j <= 100; j++) {
                if (j * a[i] > mid) {
                    minn = min(minn, j * p[i]);
                    break;
                }
                long long remaining = mid - j * a[i];
                long long k = remaining / b[i];
                if (remaining % b[i] != 0) {
                    k++;
                }
                minn = min(minn, j * p[i] + k * q[i]);
            }
            for (int j = 0; j <= 100; j++) {
                if (j * b[i] > mid) {
                    minn = min(minn, j * q[i]);
                    break;
                }
                long long remaining = mid - j * b[i];
                long long k = remaining / a[i];
                if (remaining % a[i] != 0) {
                    k++;
                }
                minn = min(minn, j * q[i] + k * p[i]);
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
    cout << ans << endl;
    return 0;
}