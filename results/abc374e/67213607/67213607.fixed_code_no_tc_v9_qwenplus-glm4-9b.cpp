#include<bits/stdc++.h>
using namespace std;
long long n, x;
long long a[105], p[105], b[105], q[105];
long long l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 1;
    r = 1000000005;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        for (int i = 0; i < n; i++) {
            minn = 0;
            // Calculate the minimum cost for using a[i] and p[i] at distance mid-a[i]*j
            long long delta1 = mid - a[i] * b[i];
            if (delta1 <= 0) {
                minn = (b[i] + delta1 - 1) / delta1 * p[i];
            } else {
                minn = b[i] * p[i] + ((delta1 + b[i] - 1) / b[i]) * q[i];
            }
            // Calculate the minimum cost for using b[i] and q[i] at distance mid-b[i]*j
            long long delta2 = mid - b[i] * a[i];
            if (delta2 <= 0) {
                minn = (a[i] + delta2 - 1) / delta2 * q[i];
            } else {
                minn = a[i] * q[i] + ((delta2 + a[i] - 1) / a[i]) * p[i];
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