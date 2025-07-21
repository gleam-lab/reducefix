#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0;
    r = 1e14;  // Adjusted upper bound based on problem constraints
    ans = -1;  // Initialize to -1 as we are looking for the maximum value
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            minn = 1e18;  // Initialize to a large number
            for (int j = 0; j <= b[i]; j++) {
                long long cost = j * p[i];
                if ((mid - j * a[i]) <= 0) {
                    cost = min(cost, j * p[i]);
                } else if ((mid - j * a[i]) % b[i] == 0) {
                    cost = min(cost, j * p[i] + (mid - j * a[i]) / b[i] * q[i]);
                } else {
                    cost = min(cost, j * p[i] + ((mid - j * a[i]) / b[i] + 1) * q[i]);
                }
                minn = min(minn, cost);
            }
            for (int j = 0; j <= a[i]; j++) {
                long long cost = j * q[i];
                if ((mid - j * b[i]) <= 0) {
                    cost = min(cost, j * q[i]);
                } else if ((mid - j * b[i]) % a[i] == 0) {
                    cost = min(cost, j * q[i] + (mid - j * b[i]) / a[i] * p[i]);
                } else {
                    cost = min(cost, j * q[i] + ((mid - j * b[i]) / a[i] + 1) * p[i]);
                }
                minn = min(minn, cost);
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