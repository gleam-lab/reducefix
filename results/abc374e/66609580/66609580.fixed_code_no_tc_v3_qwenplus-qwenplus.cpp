#include <bits/stdc++.h>
using namespace std;
#define dout cout

int n;
long long a[110], b[110], p[110], q[110], x;

inline long long lcm(long long x, long long y) {
    return x / __gcd(x, y) * y;
}

inline bool check(long long v){
    long long cnt = 0;
    for (int i = 1; i <= n; i++){
        long long _lcm = lcm(a[i], b[i]);
        long long full_cycles = v / _lcm;
        
        // Count contribution from full cycles
        long long cost_per_cycle = min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i]));
        cnt += full_cycles * cost_per_cycle;
        
        if (cnt >= x) return false;
        
        // Check remaining part after full cycles
        long long rem = v % _lcm;
        long long min_cost = LLONG_MAX;
        
        // Brute force the remainder part
        for (long long j = 0; j * a[i] <= rem; j++) {
            long long rem_after_a = rem - j * a[i];
            long long k = (rem_after_a + b[i] - 1) / b[i]; // ceil division
            if (k < 0) k = 0;
            min_cost = min(min_cost, j * p[i] + k * q[i]);
            
            // Early exit if we already exceed x
            if (cnt + min_cost >= x) break;
        }
        
        cnt += min_cost;
        if (cnt >= x) return false;
    }
    return true;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> x;
    for (int i = 0; ++i <= n;) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long l = 0, r = (long long)(4e18); // Large enough upper bound
    
    for (; l + 1 < r;) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}