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

    auto can_achieve = [&](long long k) -> bool {
        long long total_cost = 0;
        for (long long i = 0; i < n; ++i) {
            long long min_cost = numeric_limits<long long>::max();
            
            // Try all combinations of item A and B to meet the requirement k
            for (long long j = 0; j <= b[i] && j * a[i] <= k; ++j) {
                long long remaining = k - j * a[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * p[i]);
                } else {
                    long long needed_b = (remaining + b[i] - 1) / b[i]; // ceil division
                    if (needed_b <= numeric_limits<long long>::max() - j * p[i]) {
                        min_cost = min(min_cost, j * p[i] + needed_b * q[i]);
                    }
                }
            }

            for (long long j = 0; j <= a[i] && j * b[i] <= k; ++j) {
                long long remaining = k - j * b[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * q[i]);
                } else {
                    long long needed_a = (remaining + a[i] - 1) / a[i]; // ceil division
                    if (needed_a <= numeric_limits<long long>::max() - j * q[i]) {
                        min_cost = min(min_cost, j * q[i] + needed_a * p[i]);
                    }
                }
            }

            if (min_cost == numeric_limits<long long>::max()) return false;
            total_cost += min_cost;
            if (total_cost > x) return false;
        }
        return total_cost <= x;
    };

    long long low = 0, high = 1e18;
    long long answer = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (can_achieve(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}