#include <bits/stdc++.h>
using namespace std;

long long n, x, a[105], p[105], b[105], q[105];

long long computeCost(long long mid) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        long long min_cost = LLONG_MAX;
        // Try all possible j for machine A (0 <= j <= min(mid, a[i]))
        long long max_j = min(mid, a[i]);
        for (long long j = 0; j <= max_j; ++j) {
            long long remaining = mid - j;
            if (remaining <= 0) {
                min_cost = min(min_cost, j * p[i]);
            } else {
                long long k = (remaining + b[i] - 1) / b[i];  // ceil division
                if (k <= q[i]) {  // Ensure that k doesn't exceed max possible q (but q[i] is cost per unit)
                    min_cost = min(min_cost, j * p[i] + k * q[i]);
                }
            }
        }
        // Try all possible j for machine B (0 <= j <= min(mid, b[i]))
        max_j = min(mid, b[i]);
        for (long long j = 0; j <= max_j; ++j) {
            long long remaining = mid - j;
            if (remaining <= 0) {
                min_cost = min(min_cost, j * q[i]);
            } else {
                long long k = (remaining + a[i] - 1) / a[i];  // ceil division
                if (k <= p[i]) {  // Ensure that k doesn't exceed max possible p
                    min_cost = min(min_cost, j * q[i] + k * p[i]);
                }
            }
        }
        sum += min_cost;
        if (sum > x) break;  // Early termination if sum exceeds x
    }
    return sum;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long cost = computeCost(mid);
        if (cost <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}