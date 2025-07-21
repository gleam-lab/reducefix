#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    cin >> n >> x;

    vector<long long> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    auto is_possible = [&](long long target) -> bool {
        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            long long min_cost = 1e18;

            // Try all possible numbers of first item type (up to a[i])
            for (long long j = 0; j <= a[i]; ++j) {
                long long remaining = max(0LL, target - j * a[i]);
                long long k = (remaining + b[i] - 1) / b[i]; // ceil division
                if (k > b[i]) continue; // not enough of second item
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }

            // Try all possible numbers of second item type (up to b[i])
            for (long long j = 0; j <= b[i]; ++j) {
                long long remaining = max(0LL, target - j * b[i]);
                long long k = (remaining + a[i] - 1) / a[i]; // ceil division
                if (k > a[i]) continue; // not enough of first item
                min_cost = min(min_cost, j * q[i] + k * p[i]);
            }

            total_cost += min_cost;
            if (total_cost > x) return false;
        }
        return true;
    };

    long long l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (is_possible(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}