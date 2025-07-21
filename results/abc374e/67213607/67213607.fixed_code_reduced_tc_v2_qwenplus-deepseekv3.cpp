#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0;
    r = 1e18; // Adjust the upper bound to a sufficiently large value
    ans = 0;
    while(l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        bool valid = true;
        for(int i = 1; i <= n; i++) {
            minn = LLONG_MAX;
            // Iterate over possible j (number of a[i] units)
            long long max_j = min(mid / a[i], b[i]) + 2;
            for(long long j = 0; j <= max_j; j++) {
                if(j > b[i]) continue;
                long long remaining = mid - j * a[i];
                if(remaining <= 0) {
                    minn = min(minn, j * p[i]);
                } else {
                    long long k = (remaining + b[i] - 1) / b[i]; // ceil division
                    if(k > a[i]) continue;
                    minn = min(minn, j * p[i] + k * q[i]);
                }
            }
            // Iterate over possible k (number of b[i] units)
            long long max_k = min(mid / b[i], a[i]) + 2;
            for(long long k = 0; k <= max_k; k++) {
                if(k > a[i]) continue;
                long long remaining = mid - k * b[i];
                if(remaining <= 0) {
                    minn = min(minn, k * q[i]);
                } else {
                    long long j = (remaining + a[i] - 1) / a[i]; // ceil division
                    if(j > b[i]) continue;
                    minn = min(minn, k * q[i] + j * p[i]);
                }
            }
            if(minn == LLONG_MAX) {
                valid = false;
                break;
            }
            sum += minn;
            if(sum > x) {
                valid = false;
                break;
            }
        }
        if(valid && sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}