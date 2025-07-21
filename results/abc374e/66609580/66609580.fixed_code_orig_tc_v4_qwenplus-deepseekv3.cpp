#include <bits/stdc++.h>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long gcd_ab = __gcd(a[i], b[i]);
        long long lcm_ab = a[i] / gcd_ab * b[i];
        long long full_cycles = v / lcm_ab;
        long long cost_full_cycle = min(full_cycles * p[i] * (lcm_ab / a[i]), full_cycles * q[i] * (lcm_ab / b[i]));
        
        long long remaining = v % lcm_ab;
        long long min_residual_cost = LLONG_MAX;
        
        // Try using a[i] up to remaining / a[i] + 1
        long long max_j = remaining / a[i] + 2;
        for (long long j = 0; j <= max_j; ++j) {
            long long used_a = j * a[i];
            if (used_a > remaining) break;
            long long remaining_part = remaining - used_a;
            long long k = (remaining_part + b[i] - 1) / b[i];  // ceiling division
            long long cost = j * p[i] + k * q[i];
            if (cost < min_residual_cost) {
                min_residual_cost = cost;
            }
        }
        
        // Also consider using b[i] more than what's covered by the above loop
        long long max_k = remaining / b[i] + 2;
        for (long long k = 0; k <= max_k; ++k) {
            long long used_b = k * b[i];
            if (used_b > remaining) break;
            long long remaining_part = remaining - used_b;
            long long j = (remaining_part + a[i] - 1) / a[i];  // ceiling division
            long long cost = j * p[i] + k * q[i];
            if (cost < min_residual_cost) {
                min_residual_cost = cost;
            }
        }
        
        total += cost_full_cycle + min_residual_cost;
        if (total > x) {
            return false;
        }
    }
    return total <= x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long low = 0, high = 1LL << 60;
    long long answer = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << answer << '\n';
    
    return 0;
}