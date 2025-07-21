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
            
            // Try all possible usages of first item
            for (long long j = 0; j <= b[i]; ++j) {
                long long produced = j * a[i];
                if (produced >= k) {
                    min_cost = min(min_cost, j * p[i]);
                    continue;
                }
                
                long long remaining = k - produced;
                long long need_second = (remaining + b[i] - 1) / b[i];
                if (need_second <= q[i]) {
                    min_cost = min(min_cost, j * p[i] + need_second * q[i]);
                }
            }
            
            // Try all possible usages of second item
            for (long long j = 0; j <= a[i]; ++j) {
                long long produced = j * b[i];
                if (produced >= k) {
                    min_cost = min(min_cost, j * q[i]);
                    continue;
                }
                
                long long remaining = k - produced;
                long long need_first = (remaining + a[i] - 1) / a[i];
                if (need_first <= p[i]) {
                    min_cost = min(min_cost, j * q[i] + need_first * p[i]);
                }
            }
            
            if (min_cost == numeric_limits<long long>::max()) return false;
            total_cost += min_cost;
            if (total_cost > x) return false;
        }
        return total_cost <= x;
    };

    long long left = 0, right = 1e18;
    long long ans = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (is_possible(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}