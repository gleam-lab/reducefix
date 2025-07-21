#include <bits/stdc++.h>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        long long gcd_ab = __gcd(a[i], b[i]);
        long long lcm_ab = a[i] / gcd_ab * b[i];
        
        long long full_cycles = v / lcm_ab;
        long long cost_full_cycle = min(full_cycles * p[i] * (lcm_ab / a[i]), 
                                        full_cycles * q[i] * (lcm_ab / b[i]));
        long long remaining_time = v % lcm_ab;
        
        long long min_remaining_cost = LLONG_MAX;
        for (long long j = 0; j * a[i] <= remaining_time; ++j) {
            long long remaining_after_a = remaining_time - j * a[i];
            long long k = (remaining_after_a + b[i] - 1) / b[i]; // ceil division
            long long current_cost = j * p[i] + k * q[i];
            if (current_cost < min_remaining_cost) {
                min_remaining_cost = current_cost;
            }
        }
        
        total_cost += cost_full_cycle + min_remaining_cost;
        if (total_cost > x) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long left = 0;
    long long right = 1LL << 60; // Sufficiently large upper bound
    
    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << left << endl;
    return 0;
}