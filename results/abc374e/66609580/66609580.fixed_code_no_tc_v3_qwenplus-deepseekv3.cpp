#include <bits/stdc++.h>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long total_cost = 0;
    for (int i = 1; i <= n; i++) {
        long long gcd_ab = __gcd(a[i], b[i]);
        long long lcm_ab = a[i] / gcd_ab * b[i];
        
        // Calculate full cycles
        long long full_cycles = v / lcm_ab;
        long long full_cost = min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i])) * full_cycles;
        
        // Calculate remaining time
        long long remaining = v % lcm_ab;
        long long min_remaining_cost = LLONG_MAX;
        
        // Find optimal combination for remaining time
        for (long long j = 0; j * a[i] <= remaining; j++) {
            long long remaining_b = remaining - j * a[i];
            long long k = max(0LL, (remaining_b + b[i] - 1) / b[i]);  // ceil(remaining_b / b[i])
            min_remaining_cost = min(min_remaining_cost, j * p[i] + k * q[i]);
        }
        
        total_cost += full_cost + min_remaining_cost;
        if (total_cost > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long l = 0, r = 1LL << 60;
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    cout << l << endl;
    return 0;
}