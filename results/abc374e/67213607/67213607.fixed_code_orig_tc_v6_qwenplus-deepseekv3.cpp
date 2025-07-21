#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans = 0;

long long calculate_cost(long long mid) {
    long long total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        long long min_cost = LLONG_MAX;
        long long max_j = min(mid / a[i] + 1, b[i]);
        for (long long j = 0; j <= max_j; ++j) {
            long long remaining = mid - j * a[i];
            if (remaining <= 0) {
                min_cost = min(min_cost, j * p[i]);
            } else {
                long long k = (remaining + b[i] - 1) / b[i]; // ceiling division
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }
        }
        long long max_k = min(mid / b[i] + 1, a[i]);
        for (long long k = 0; k <= max_k; ++k) {
            long long remaining = mid - k * b[i];
            if (remaining <= 0) {
                min_cost = min(min_cost, k * q[i]);
            } else {
                long long j = (remaining + a[i] - 1) / a[i]; // ceiling division
                min_cost = min(min_cost, k * q[i] + j * p[i]);
            }
        }
        total_cost += min_cost;
        if (total_cost > x) break; // Early termination if budget exceeded
    }
    return total_cost;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0;
    r = 1e18; // Sufficiently large upper bound
    while (l <= r) {
        mid = (l + r) / 2;
        long long cost = calculate_cost(mid);
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