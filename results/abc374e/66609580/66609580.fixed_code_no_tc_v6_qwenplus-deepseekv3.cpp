#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110],b[110],p[110],q[110],x;

inline bool check(long long v) {
    long long total_cost = 0;
    for (int i = 1; i <= n; i++) {
        long long g = __gcd(a[i], b[i]);
        long long lcm = a[i] / g * b[i];
        
        // Calculate full cycles
        long long full_cycles = v / lcm;
        long long full_cost = min(full_cycles * p[i] * (lcm / a[i]), 
                                 full_cycles * q[i] * (lcm / b[i]));
        
        // Calculate remaining after full cycles
        long long remaining = v % lcm;
        long long min_remaining_cost = LLONG_MAX;
        
        // Try all possible a[i] multiples for the remaining part
        long long max_a = remaining / a[i] + 2;
        for (long long k = 0; k <= max_a; k++) {
            long long a_part = k * a[i];
            if (a_part > remaining) break;
            
            long long b_needed = remaining - a_part;
            long long b_count = (b_needed + b[i] - 1) / b[i]; // ceiling division
            long long cost = k * p[i] + b_count * q[i];
            min_remaining_cost = min(min_remaining_cost, cost);
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
    cout << l;
    return 0;
}