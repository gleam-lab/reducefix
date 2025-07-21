#include <bits/stdc++.h>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0 || b[i] == 0) continue;  // handle division by zero
        
        long long gcd_ab = __gcd(a[i], b[i]);
        long long lcm_ab = a[i] / gcd_ab * b[i];
        
        // Calculate full cycles
        long long full_cycles = v / lcm_ab;
        long long min_per_cycle = min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i]));
        long long cycle_score = full_cycles * min_per_cycle;
        
        // Calculate remaining time after full cycles
        long long remaining = v % lcm_ab;
        
        // Find best way to use remaining time
        long long best = LLONG_MAX;
        long long max_a = remaining / a[i];
        for (long long j = 0; j <= max_a + 1; j++) {
            long long a_time = j * a[i];
            if (a_time > remaining) continue;
            long long b_time = remaining - a_time;
            long long b_count = b_time / b[i];
            if (b_time % b[i] != 0) b_count++;
            long long current = j * p[i] + b_count * q[i];
            best = min(best, current);
        }
        
        total += cycle_score + best;
        if (total > x) return false;
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
    
    long long left = 0, right = 1e18;
    long long answer = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer;
    return 0;
}