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
            minn = 0;
            for (int j = 0; j <= b[i]; j++) {
                long long term1 = mid - j * a[i];
                if (term1 <= 0) {
                    minn = max(minn, j * p[i]);
                } else if (term1 % b[i] == 0) {
                    minn = max(minn, j * p[i] + (term1 / b[i]) * q[i]);
                } else {
                    minn = max(minn, j * p[i] + ((term1 / b[i]) + 1) * q[i]);
                }
            }
            for (int j = 0; j <= a[i]; j++) {
                long long term2 = mid - j * b[i];
                if (term2 <= 0) {
                    minn = max(minn, j * q[i]);
                } else if (term2 % a[i] == 0) {
                    minn = max(minn, j * q[i] + (term2 / a[i]) * p[i]);
                } else {
                    minn = max(minn, j * q[i] + ((term2 / a[i]) + 1) * p[i]);
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
    cout << ans << endl;
    return 0;
}