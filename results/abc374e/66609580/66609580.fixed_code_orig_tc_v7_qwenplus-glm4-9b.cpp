#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int n;
vector<long long> a, b, p, q;

inline long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        long long _lcm = lcm(a[i], b[i]);
        long long vm = max(0LL, (v / _lcm - 1) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        cnt += vm;

        long long val = max(0LL, v / _lcm - 1) * _lcm, ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; ++j) {
            long long tmp = (v - val - j * a[i]) / b[i];
            ms = min(ms, j * p[i] + tmp * q[i]);
        }
        cnt += ms;
        if (cnt > v) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> v;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = v + 1;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}