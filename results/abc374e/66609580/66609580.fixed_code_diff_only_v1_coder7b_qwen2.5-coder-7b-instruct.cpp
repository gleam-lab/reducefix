#include <bits/stdc++.h>
using namespace std;

#define dout cout

const int MAXN = 110;

int n;
long long a[MAXN], b[MAXN], p[MAXN], q[MAXN], x;

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long _lcm = (a[i] / gcd(a[i], b[i])) * b[i];
        long long vm = max(0LL, (v / _lcm - 1) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        cnt += vm;
        long long val = max(0LL, v / _lcm - 1) * _lcm;
        long long ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; j++) {
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
    for (int i = 1; i <= n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];
    long long l = 0, r = UINT64_MAX;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1;
}