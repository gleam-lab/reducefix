#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    cin >> n >> x;

    vector<long long> a(n), p(n), b(n), q(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    auto is_possible = [&](long long k) -> bool {
        long long total_cost = 0;
        for (long long i = 0; i < n; ++i) {
            long long min_cost = numeric_limits<long long>::max();
            // Try all possible number of type A candies bought
            for (long long j = 0; j <= b[i] && j * a[i] <= k; ++j) {
                long long remaining = k - j * a[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * p[i]);
                    continue;
                }
                long long needed_b = (remaining + b[i] - 1) / b[i]; // ceil division
                min_cost = min(min_cost, j * p[i] + needed_b * q[i]);
            }
            // Try all possible number of type B candies bought
            for (long long j = 0; j <= a[i] && j * b[i] <= k; ++j) {
                long long remaining = k - j * b[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * q[i]);
                    continue;
                }
                long long needed_a = (remaining + a[i] - 1) / a[i]; // ceil division
                min_cost = min(min_cost, j * q[i] + needed_a * p[i]);
            }
            if (min_cost > x) return false;
            total_cost += min_cost;
            if (total_cost > x) return false;
        }
        return true;
    };

    long long low = 0, high = 2e18;
    long long ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (is_possible(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}