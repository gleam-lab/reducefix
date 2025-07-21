#include<bits/stdc++.h>
using namespace std;
#define MAXN 100

long long n, x;
long long a[MAXN + 1], b[MAXN + 1], p[MAXN + 1], q[MAXN + 1];

long long minCost(long long mid) {
    long long cost = 0;
    for (int i = 1; i <= n; i++) {
        // Calculate cost for using `p[i]` and `q[i]` fees
        long long maxDistance = mid / (a[i]*b[i]);
        if (mid % (a[i]*b[i]) == 0) {
            // Evenly distributed over `a[i]` and `b[i]`
            cost += maxDistance * (p[i] + q[i]);
        } else {
            // Odd distribution
            cost += maxDistance * (p[i] + q[i]);
            if (mid - maxDistance * a[i]*b[i] >= 0) {
                cost += (mid - maxDistance * a[i]*b[i]) / b[i] * q[i];
            }
            if (mid - (maxDistance - 1) * a[i]*b[i] >= 0) {
                cost += (mid - (maxDistance - 1) * a[i]*b[i]) / a[i] * p[i];
            }
        }
    }
    return cost;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1000000005;
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (minCost(mid) <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}