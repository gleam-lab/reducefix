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

    auto can_make = [&](long long target) -> bool {
        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            long long min_cost = 1e18;
            // Try using j of a[i], rest with b[i]
            for (long long j = 0; j <= min(target, a[i]); ++j) {
                long long needed_b = max(0LL, (target - j * b[i] + a[i] - 1) / a[i]);
                if (j * b[i] + needed_b * a[i] >= target) {
                    min_cost = min(min_cost, j * q[i] + needed_b * p[i]);
                }
            }
            // Try using j of b[i], rest with a[i]
            for (long long j = 0; j <= min(target, b[i]); ++j) {
                long long needed_a = max(0LL, (target - j * a[i] + b[i] - 1) / b[i]);
                if (j * a[i] + needed_a * b[i] >= target) {
                    min_cost = min(min_cost, j * p[i] + needed_a * q[i]);
                }
            }
            total_cost += min_cost;
            if (total_cost > x) return false;
        }
        return true;
    };

    long long l = 0, r = 1e6, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (can_make(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}