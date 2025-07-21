#include<bits/stdc++.h>
using namespace std;
long long n, x, ans = 0;
int a[105], b[105], p[105], q[105];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> p[i] >> q[i];
    }
    long long l = 0, r = 1000000005;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            long long minn = 210000000000000000;
            // Calculate the minimum cost for the first direction
            for (int j = 0; j <= b[i]; j++) {
                if (mid - j * a[i] <= 0) {
                    minn = min(minn, j * p[i]);
                } else {
                    minn = min(minn, j * p[i] + (mid - j * a[i]) / b[i] * q[i]);
                }
            }
            // Calculate the minimum cost for the second direction
            for (int j = 0; j <= a[i]; j++) {
                if (mid - j * b[i] <= 0) {
                    minn = min(minn, j * q[i]);
                } else {
                    minn = min(minn, j * q[i] + (mid - j * b[i]) / a[i] * p[i]);
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
}