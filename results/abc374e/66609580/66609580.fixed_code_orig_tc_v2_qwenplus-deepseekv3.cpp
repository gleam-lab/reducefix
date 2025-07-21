#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110],b[110],p[110],q[110],x;

inline bool check(long long v){
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long lcm = a[i] / __gcd(a[i], b[i]) * b[i];
        long long full_cycles = v / lcm;
        long long remaining = v % lcm;
        
        // Calculate maximum tasks for full cycles
        long long tasks_full = full_cycles * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i]));
        
        // Calculate maximum tasks for remaining time
        long long max_remaining = 0;
        for (long long j = 0; j * a[i] <= remaining; j++) {
            long long time_left = remaining - j * a[i];
            long long b_tasks = time_left / b[i];
            max_remaining = max(max_remaining, j * p[i] + b_tasks * q[i]);
        }
        
        cnt += tasks_full + max_remaining;
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