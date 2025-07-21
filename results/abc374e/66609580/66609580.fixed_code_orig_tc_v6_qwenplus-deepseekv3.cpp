#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110],b[110],p[110],q[110],x;

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long gcd_ab = __gcd(a[i], b[i]);
        long long lcm = a[i] / gcd_ab * b[i];
        
        long long full_cycles = v / lcm;
        long long full_cost = min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i]));
        cnt += full_cycles * full_cost;
        
        long long remaining = v % lcm;
        long long min_cost = LLONG_MAX;
        
        // Try all possible a[i] purchases in the remaining time
        long long max_a = remaining / a[i] + 2;  // +2 for safety
        for (long long j = 0; j <= max_a; j++) {
            long long a_time = j * a[i];
            if (a_time > remaining) continue;
            long long b_time = remaining - a_time;
            long long b_count = (b_time + b[i] - 1) / b[i];  // ceiling division
            min_cost = min(min_cost, j * p[i] + b_count * q[i]);
        }
        
        cnt += min_cost;
        if (cnt > x) return false;
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