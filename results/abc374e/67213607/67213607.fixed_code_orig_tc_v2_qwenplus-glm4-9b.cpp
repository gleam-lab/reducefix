#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0, r = 1e9;
    while (l < r) {
        mid = (l + r + 1) / 2;
        sum = 0;
        for (int i = 0; i < n; i++) {
            minn = 1e18;
            for (int j = 0; j <= b[i]; j++) {
                long long pos = mid - j * a[i];
                if (pos <= 0) minn = min(minn, j * p[i]);
                else if (pos % b[i] == 0) minn = min(minn, j * p[i] + (pos / b[i]) * q[i]);
                else minn = min(minn, j * p[i] + ((pos / b[i]) + 1) * q[i]);
            }
            for (int j = 0; j <= a[i]; j++) {
                long long pos = mid - j * b[i];
                if (pos <= 0) minn = min(minn, j * q[i]);
                else if (pos % a[i] == 0) minn = min(minn, j * q[i] + (pos / a[i]) * p[i]);
                else minn = min(minn, j * q[i] + ((pos / a[i]) + 1) * p[i]);
            }
            sum += minn;
        }
        if (sum <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}