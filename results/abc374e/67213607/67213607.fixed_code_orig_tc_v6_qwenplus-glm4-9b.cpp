#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;

long long calc_cost(long long mid) {
    sum = 0;
    for (int i = 1; i <= n; i++) {
        minn = 2e18;
        for (int j = 0; j <= b[i]; j++) {
            long long cost = (mid - j * a[i]) <= 0 ? j * p[i] : (mid - j * a[i]) / b[i] * q[i] + ((mid - j * a[i]) / b[i] + 1) * p[i];
            minn = min(minn, cost);
        }
        for (int j = 0; j <= a[i]; j++) {
            long long cost = (mid - j * b[i]) <= 0 ? j * q[i] : (mid - j * b[i]) / a[i] * p[i] + ((mid - j * b[i]) / a[i] + 1) * q[i];
            minn = min(minn, cost);
        }
        sum += minn;
    }
    return sum;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 1;
    r = 1e9 + 5;
    ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (calc_cost(mid) <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}