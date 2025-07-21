#include<bits/stdc++.h>
using namespace std;
long long n, x, ans;
int a[105], b[105], p[105], q[105];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = 1000000005;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            long long minn = LLONG_MAX;
            long long maxCover = (mid / a[i]) * b[i];
            for (long long j = 0; j <= maxCover; j++) {
                long long cost = (mid - j * a[i]) <= 0 ? j * p[i] : j * p[i] + ((mid - j * a[i]) / b[i] + 1) * q[i];
                minn = min(minn, cost);
            }
            sum += minn;
            maxCover = (mid / b[i]) * a[i];
            for (long long j = 0; j <= maxCover; j++) {
                long long cost = (mid - j * b[i]) <= 0 ? j * q[i] : j * q[i] + ((mid - j * b[i]) / a[i] + 1) * p[i];
                minn = min(minn, cost);
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