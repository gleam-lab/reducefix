#include <bits/stdc++.h>
using namespace std;

int n;
long long x;
long long a[110], b[110], p[110], q[110];

bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        long long lcm = a[i] / __gcd(a[i], b[i]) * b[i];
        long long full_cycles = v / lcm;
        long long remaining = v % lcm;
        
        long long min_cost = LLONG_MAX;
        for (long long j = 0; j * a[i] <= remaining; j++) {
            long long k = (remaining - j * a[i]) / b[i];
            if (remaining - j * a[i] - k * b[i] > 0) k++;
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        
        long long full_cost = min(full_cycles * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i])) + min_cost,
                                 (full_cycles + 1) * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i])));
        total += full_cost;
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
    cout << l << endl;
    
    return 0;
}