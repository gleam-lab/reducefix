#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110],b[110],p[110],q[110],x;

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        long long gcd = __gcd(a[i], b[i]);
        long long lcm = a[i] / gcd * b[i];
        
        long long full_cycles = v / lcm;
        long long remaining = v % lcm;
        
        // Cost for full cycles
        long long cycle_cost = min(full_cycles * p[i] * (lcm / a[i]), 
                                  full_cycles * q[i] * (lcm / b[i]));
        
        // Cost for remaining time
        long long remaining_cost = LLONG_MAX;
        for (long long j = 0; j * a[i] <= remaining; j++) {
            long long rem = remaining - j * a[i];
            long long k = max(0LL, (rem + b[i] - 1) / b[i]);  // ceil(rem/b[i])
            remaining_cost = min(remaining_cost, j * p[i] + k * q[i]);
        }
        
        total += cycle_cost + remaining_cost;
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
    
    long long l = 0, r = 1LL << 60;
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