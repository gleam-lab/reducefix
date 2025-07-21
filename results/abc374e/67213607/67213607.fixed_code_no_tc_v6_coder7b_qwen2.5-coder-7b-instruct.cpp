#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const long long INF = 210000000000000000LL;

long long n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN], l, r, mid, ans, minn, sum;

bool check(long long m) {
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        minn = INF;
        for (int j = 0; j <= b[i]; ++j) {
            if ((m - j * a[i]) <= 0) {
                minn = min(minn, j * p[i]);
            } else if ((m - j * a[i]) % b[i] == 0) {
                minn = min(minn, j * p[i] + (m - j * a[i]) / b[i] * q[i]);
            } else {
                minn = min(minn, j * p[i] + ((m - j * a[i]) / b[i] + 1) * q[i]);
            }
        }
        for (int j = 0; j <= a[i]; ++j) {
            if ((m - j * b[i]) <= 0) {
                minn = min(minn, j * q[i]);
            } else if ((m - j * b[i]) % a[i] == 0) {
                minn = min(minn, j * q[i] + (m - j * b[i]) / a[i] * p[i]);
            } else {
                minn = min(minn, j * q[i] + ((m - j * b[i]) / a[i] + 1) * p[i]);
            }
        }
        sum += minn;
    }
    return sum <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
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
    cout << ans;
    return 0;
}