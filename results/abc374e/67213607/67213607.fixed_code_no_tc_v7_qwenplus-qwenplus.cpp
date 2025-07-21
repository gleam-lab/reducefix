#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n), p(n), b(n), q(n);
    
    for (long long i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 2e18, ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long total_cost = 0;

        for (long long i = 0; i < n; ++i) {
            long long min_cost = 1e18;

            // Try all possible purchases of item A (up to what can be afforded with mid)
            for (long long j = 0; j <= b[i]; ++j) {
                long long have = j * a[i];
                if (have > mid) break;
                long long remaining = mid - have;
                long long needed_B = (remaining + b[i] - 1) / b[i]; // ceil division
                if (needed_B <= q[i]) {
                    long long cost = j * p[i] + needed_B * q[i];
                    min_cost = min(min_cost, cost);
                }
            }

            // Try all possible purchases of item B
            for (long long j = 0; j <= a[i]; ++j) {
                long long have = j * b[i];
                if (have > mid) break;
                long long remaining = mid - have;
                long long needed_A = (remaining + a[i] - 1) / a[i]; // ceil division
                if (needed_A <= p[i]) {
                    long long cost = j * q[i] + needed_A * p[i];
                    min_cost = min(min_cost, cost);
                }
            }

            total_cost += min_cost;
            if (total_cost > x) break; // Early exit if already too expensive
        }

        if (total_cost <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
}