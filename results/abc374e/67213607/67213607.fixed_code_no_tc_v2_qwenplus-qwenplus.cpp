#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    long long a[105], p[105], b[105], q[105];
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 2000000000; // More reasonable upper bound
    long long ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long total_cost = 0;

        for (int i = 1; i <= n; ++i) {
            long long min_cost = 1e18; // Use a large number for initialization

            // Try all possible usages of A-type items
            for (long long j = 0; j <= b[i] && j * a[i] <= mid; ++j) {
                long long remaining = mid - j * a[i];
                long long k = (remaining + b[i] - 1) / b[i]; // Ceiling division
                if (k < 0) k = 0;
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }

            // Try all possible usages of B-type items
            for (long long j = 0; j <= a[i] && j * b[i] <= mid; ++j) {
                long long remaining = mid - j * b[i];
                long long k = (remaining + a[i] - 1) / a[i]; // Ceiling division
                if (k < 0) k = 0;
                min_cost = min(min_cost, j * q[i] + k * p[i]);
            }

            total_cost += min_cost;
            if (total_cost > x) break; // Early exit if budget is exceeded
        }

        if (total_cost <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}