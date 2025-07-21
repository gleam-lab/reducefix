#include<bits/stdc++.h>
using namespace std;

long long n, x;
long long a[105], p[105], b[105], q[105];

long long compute_cost(long long days) {
    long long total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        long long min_cost = LLONG_MAX;
        // Consider using method A j times and method B for the remaining
        for (long long j = 0; j <= (days / a[i] + 1); ++j) {
            long long remaining_days = days - j * a[i];
            if (remaining_days < 0) {
                min_cost = min(min_cost, j * p[i]);
                continue;
            }
            long long k = (remaining_days + b[i] - 1) / b[i]; // ceiling division
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        // Also consider using method B j times and method A for the remaining
        for (long long j = 0; j <= (days / b[i] + 1); ++j) {
            long long remaining_days = days - j * b[i];
            if (remaining_days < 0) {
                min_cost = min(min_cost, j * q[i]);
                continue;
            }
            long long k = (remaining_days + a[i] - 1) / a[i]; // ceiling division
            min_cost = min(min_cost, j * q[i] + k * p[i]);
        }
        total_cost += min_cost;
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