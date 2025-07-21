#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline long long gcd(long long x, long long y) {
    while (y != 0) {
        long long t = y;
        y = x % y;
        x = t;
    }
    return x;
}

long long lcm(long long x, long long y) {
    return (x / gcd(x, y)) * y;
}

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long lcm_ab = lcm(a[i], b[i]);
        long long val = (v / lcm_ab - 1) * lcm_ab;
        long long max_part = val / a[i];
        long long min_part = val / b[i];
        cnt += max(0LL, (v / lcm_ab - 1) * (min_part * p[i] + max_part * q[i]));
        
        long long ms = LLONG_MAX;
        for (long long j = 0; j * a[i] <= v - val; ++j) {
            long long remaining = v - val - j * a[i];
            if (remaining < 0) break;
            ms = min(ms, j * p[i] + max(0LL, (remaining / b[i]) * q[i]));
        }
        cnt += ms;
        if (cnt > x) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = (1LL << 62) - 1;
    while (l < r) {
        long long mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}