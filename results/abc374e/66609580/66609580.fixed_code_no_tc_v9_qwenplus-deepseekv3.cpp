#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110],b[110],p[110],q[110],x;

inline bool check(long long v){
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        long long lcm_ab = a[i] / __gcd(a[i], b[i]) * b[i];
        long long full_cycles = v / lcm_ab;
        long long remaining = v % lcm_ab;
        
        // Calculate maximum points from full cycles
        long long points_full_cycle = min(full_cycles * p[i] * (lcm_ab / a[i]),
                                          full_cycles * q[i] * (lcm_ab / b[i]));
        
        // Calculate maximum points from remaining time
        long long max_remaining = 0;
        long long max_a = remaining / a[i];
        for (long long j = 0; j <= max_a; j++) {
            long long time_left = remaining - j * a[i];
            long long count_b = time_left / b[i];
            max_remaining = max(max_remaining, j * p[i] + count_b * q[i]);
        }
        
        total += points_full_cycle + max_remaining;
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
    
    long long l = 0, r = 1e18;
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
    return 0;
}