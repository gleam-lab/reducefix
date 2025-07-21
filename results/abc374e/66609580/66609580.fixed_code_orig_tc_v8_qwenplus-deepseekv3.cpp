#include <bits/stdc++.h>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long g = __gcd(a[i], b[i]);
        long long lcm = a[i] / g * b[i];
        long long full_cycles = v / lcm;
        long long remaining = v % lcm;
        
        long long cost_full_cycle = min(full_cycles * p[i] * (lcm / a[i]), full_cycles * q[i] * (lcm / b[i]));
        
        long long min_remaining_cost = LLONG_MAX;
        for (long long j = 0; j * a[i] <= remaining; ++j) {
            long long rem = remaining - j * a[i];
            long long k = rem / b[i];
            if (rem % b[i] != 0) ++k;
            min_remaining_cost = min(min_remaining_cost, j * p[i] + k * q[i]);
        }
        
        total += cost_full_cycle + min_remaining_cost;
        if (total > x) return false;
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