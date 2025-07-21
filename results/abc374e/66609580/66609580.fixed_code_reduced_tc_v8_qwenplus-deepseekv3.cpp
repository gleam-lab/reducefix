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
        long long items_a_full = (lcm_ab / a[i]) * full_cycles;
        long long items_b_full = (lcm_ab / b[i]) * full_cycles;
        long long cost_full = min(items_a_full * p[i], items_b_full * q[i]);
        
        // Calculate remaining time
        long long remaining_time = v % lcm_ab;
        
        // Find optimal way to produce in remaining time
        long long min_remaining_cost = LLONG_MAX;
        long long max_a_possible = remaining_time / a[i] + 1;
        
        for (long long j = 0; j <= max_a_possible; j++) {
            long long time_a = j * a[i];
            if (time_a > remaining_time) continue;
            
            long long time_b = remaining_time - time_a;
            long long items_b = time_b / b[i];
            if (time_b % b[i]) items_b++;
            
            long long current_cost = j * p[i] + items_b * q[i];
            if (current_cost < min_remaining_cost) {
                min_remaining_cost = current_cost;
            }
        }
        
        total_cost += cost_full + min_remaining_cost;
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
    
    long long left = 0;
    long long right = 1LL << 60; // Sufficiently large upper bound
    
    while (left < right) {
        long long mid = left + (right - left + 1) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    cout << left << endl;
    return 0;
}