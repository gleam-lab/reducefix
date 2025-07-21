#include <bits/stdc++.h>
using namespace std;

#define dout if(false) cerr

const int MAXN = 110;
long long a[MAXN], b[MAXN], p[MAXN], q[MAXN];

inline long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        long long _lcm = a[i] / gcd(a[i], b[i]) * b[i];
        long long vm = max(0LL, (v / _lcm - 1) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        cnt += vm;
        long long val = max(0LL, v / _lcm - 1) * _lcm, ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; ++j) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] + !!((v - val - j * a[i]) % b[i])) * q[i]));
        }
        cnt += ms;
        if (cnt > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> p[i] >> b[i] >> q[i];
    long long l = 0, r = UINT_MAX << 1;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}