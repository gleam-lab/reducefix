#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long a[110], p[110], b[110], q[110], x;

inline long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long _lcm = lcm(a[i], b[i]);
        long long vm = max(0LL, (v / _lcm - 1) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        cnt += vm;

        long long val = max(0LL, v / _lcm - 1) * _lcm;
        long long ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; j++) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] + 
                    (v - val - j * a[i]) % b[i] ? 1 : 0)) * q[i]);
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
    long long l = 0, r = 1e18;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}