#include<bits/stdc++.h>
using namespace std;

long long n, x, a[105], p[105], b[105], q[105];

long long compute_cost(long long mid) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long min_cost = LLONG_MAX;
        // Try all possible j (number of a[i] items)
        long long max_j = min(mid / a[i], b[i]);
        for (long long j = 0; j <= max_j; ++j) {
            long long remaining = mid - j * a[i];
            if (remaining <= 0) {
                min_cost = min(min_cost, j * p[i]);
            } else {
                long long k = (remaining + b[i] - 1) / b[i]; // ceil division
                if (k <= q[i]) {
                    min_cost = min(min_cost, j * p[i] + k * q[i]);
                }
            }
        }
        // Also try all possible k (number of b[i] items)
        long long max_k = min(mid / b[i], a[i]);
        for (long long k = 0; k <= max_k; ++k) {
            long long remaining = mid - k * b[i];
            if (remaining <= 0) {
                min_cost = min(min_cost, k * q[i]);
            } else {
                long long j = (remaining + a[i] - 1) / a[i]; // ceil division
                if (j <= p[i]) {
                    min_cost = min(min_cost, k * q[i] + j * p[i]);
                }
            }
        }
        total += min_cost;
    }
    return total;
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