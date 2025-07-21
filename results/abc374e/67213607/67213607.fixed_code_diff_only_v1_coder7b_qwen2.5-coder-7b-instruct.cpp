#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
long long n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN], l, r, mid, ans, minn, sum;

bool check(long long mid) {
    sum = 0;
    for (int i = 1; i <= n; i++) {
        minn = LLONG_MAX;
        for (int j = 0; j <= b[i]; j++) {
            if ((mid - j * a[i]) >= 0) {
                minn = min(minn, j * p[i] + max(0LL, (mid - j * a[i]) / b[i]) * q[i]);
            }
        }
        for (int j = 0; j <= a[i]; j++) {
            if ((mid - j * b[i]) >= 0) {
                minn = min(minn, j * q[i] + max(0LL, (mid - j * b[i]) / a[i]) * p[i]);
            }
        }
        sum += minn;
    }
    return sum <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0, r = 1000000005;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}