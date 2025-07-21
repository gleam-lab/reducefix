#include <bits/stdc++.h>
using namespace std;

long long n, x;
long long a[105], p[105], b[105], q[105];
long long l, r, mid, ans, sum;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    l = 0;
    r = 1e18; // Use larger upper bound to safely cover all possible cases

    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        bool overflow = false;

        for (int i = 1; i <= n && !overflow; ++i) {
            long long minn = 1e18;

            // Try up to b[i] of item A
            for (int j = 0; j <= b[i] && !overflow; ++j) {
                long long remaining = mid - j * a[i];
                if (remaining <= 0) {
                    minn = min(minn, j * p[i]);
                    continue;
                }
                
                long long neededB = (remaining + b[i] - 1) / b[i]; // ceil division
                if (neededB > numeric_limits<long long>::max() - j * p[i]) {
                    overflow = true;
                    break;
                }
                minn = min(minn, j * p[i] + neededB * q[i]);
            }

            // Try up to a[i] of item B
            for (int j = 0; j <= a[i] && !overflow; ++j) {
                long long remaining = mid - j * b[i];
                if (remaining <= 0) {
                    minn = min(minn, j * q[i]);
                    continue;
                }
                
                long long neededA = (remaining + a[i] - 1) / a[i]; // ceil division
                if (neededA > numeric_limits<long long>::max() - j * q[i]) {
                    overflow = true;
                    break;
                }
                minn = min(minn, j * q[i] + neededA * p[i]);
            }

            if (overflow || sum + minn > x) {
                sum = x + 1; // Make sum exceed x to reject this mid value
                break;
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