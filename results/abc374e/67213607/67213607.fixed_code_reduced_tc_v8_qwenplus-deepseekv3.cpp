#include<bits/stdc++.h>
using namespace std;

long long n, x, a[105], p[105], b[105], q[105];

long long compute_cost(long long mid) {
    long long total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        long long min_cost = LLONG_MAX;
        // Iterate over possible j (units produced by first method)
        long long max_j = min(mid / a[i] + 2, b[i]);
        for (long long j = 0; j <= max_j; ++j) {
            long long remaining = mid - j * a[i];
            long long k = 0;
            if (remaining > 0) {
                k = (remaining + b[i] - 1) / b[i]; // ceil division
            }
            if (k <= q[i]) { // Ensure we don't exceed q[i] units of the second method
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }
        }
        // Also consider cases where second method is used first
        long long max_k = min(mid / b[i] + 2, a[i]);
        for (long long k = 0; k <= max_k; ++k) {
            long long remaining = mid - k * b[i];
            long long j = 0;
            if (remaining > 0) {
                j = (remaining + a[i] - 1) / a[i]; // ceil division
            }
            if (j <= p[i]) { // Ensure we don't exceed p[i] units of the first method
                min_cost = min(min_cost, k * q[i] + j * p[i]);
            }
        }
        if (min_cost == LLONG_MAX) {
            return LLONG_MAX; // Impossible to produce mid units for this product
        }
        total_cost += min_cost;
        if (total_cost > x) {
            return LLONG_MAX; // Early exit if budget exceeded
        }
    }
    return total_cost;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long cost = compute_cost(mid);
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