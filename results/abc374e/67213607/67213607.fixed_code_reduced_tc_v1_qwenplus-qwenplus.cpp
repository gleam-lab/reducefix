#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, x;
    cin >> n >> x;
    vector<long long> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    auto isPossible = [&](long long target) -> bool {
        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            long long min_cost = 1e18;
            // Try up to max needed uses of A to reach target
            for (long long j = 0; j <= max(target / a[i], (long long)1); ++j) {
                long long val = j * a[i];
                if (val > target) break;
                long long rem = target - val;
                long long k = (rem + b[i] - 1) / b[i]; // ceil division
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }
            // Try up to max needed uses of B to reach target
            for (long long k = 0; k <= max(target / b[i], (long long)1); ++k) {
                long long val = k * b[i];
                if (val > target) break;
                long long rem = target - val;
                long long j = (rem + a[i] - 1) / a[i]; // ceil division
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }
            total_cost += min_cost;
            if (total_cost > x) return false;
        }
        return total_cost <= x;
    };

    long long low = 0, high = 1e14;
    long long ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isPossible(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
}