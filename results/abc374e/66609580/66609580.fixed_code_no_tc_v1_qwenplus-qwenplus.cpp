#include <bits/stdc++.h>
using namespace std;
#define dout if(false) cout

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        long long g = gcd(a[i], b[i]);
        long long lcm_ab = a[i] / g * b[i];
        
        // First part: full cycles
        long long full_cycles = v / lcm_ab;
        long long cost_per_full = min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i]));
        long long total_cost_full = full_cycles * cost_per_full;
        cnt += total_cost_full;

        if (cnt >= x) return false;

        // Second part: remaining values
        long long remaining = v % lcm_ab;
        long long min_cost = LLONG_MAX;
        for (long long j = 0; j * a[i] <= remaining; ++j) {
            long long rem = remaining - j * a[i];
            long long k = rem / b[i];
            if (rem % b[i] != 0) k++;
            if (k < 0) k = 0;
            long long cost = j * p[i] + k * q[i];
            min_cost = min(min_cost, cost);
        }
        cnt += min_cost;
        
        if (cnt >= x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    long long l = 0, r = 2e18;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    
    cout << (l > 0 && check(l) ? l : l - 1);
}