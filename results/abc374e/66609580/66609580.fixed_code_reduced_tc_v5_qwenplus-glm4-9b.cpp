#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

const int MAXN = 110;

int n, x;
long long a[MAXN], b[MAXN], p[MAXN], q[MAXN];

inline long long lcm(long long x, long long y) {
    return x / __gcd(x, y) * y;
}

inline long long check(long long v) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        long long _lcm = lcm(a[i], b[i]);
        long long vm = max(0LL, (v / _lcm - 1LL) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        cnt += vm;

        long long val = max(0LL, v / _lcm - 1LL) * _lcm;
        long long ms = LLONG_MAX >> 1;
        long long j = 0;
        while (j * a[i] <= v - val) {
            long long next_j = min((v - val - j * a[i]) / b[i] + 1, (LLONG_MAX >> 1));
            ms = min(ms, j * p[i] + max(0LL, (v - val - j * a[i] - next_j * b[i]) / b[i] + 1) * q[i]);
            j += next_j;
        }
        cnt += ms;
        if (cnt > x) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = LLONG_MAX;
    while (l < r - 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l;
    return 0;
}