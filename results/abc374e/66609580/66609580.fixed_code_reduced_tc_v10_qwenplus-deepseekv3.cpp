#include <bits/stdc++.h>
using namespace std;

int n;
long long x;
long long a[110], b[110], p[110], q[110];

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long lcm = a[i] / __gcd(a[i], b[i]) * b[i];
        long long full_cycles = v / lcm;
        long long partial = v % lcm;
        
        // Calculate minimum cost for full cycles
        long long full_cost = full_cycles * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i]));
        
        // Calculate minimum cost for the partial cycle
        long long min_partial = LLONG_MAX;
        long long max_a = partial / a[i] + 1;
        for (long long j = 0; j <= max_a; ++j) {
            long long remaining = partial - j * a[i];
            if (remaining < 0) remaining = 0;
            long long b_count = (remaining + b[i] - 1) / b[i];
            min_partial = min(min_partial, j * p[i] + b_count * q[i]);
        }
        
        total += full_cost + min_partial;
        if (total > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long low = 0, high = 1LL << 60;
    long long answer = 0;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
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