#include <bits/stdc++.h>
using namespace std;

#define dout cout
#define LL long long
#define MAXN 110

LL a[MAXN], b[MAXN], p[MAXN], q[MAXN], x;
LL n;

inline LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

inline bool check(LL v) {
    LL cnt = 0;
    for (int i = 1; i <= n; ++i) {
        LL _lcm = a[i] / gcd(a[i], b[i]) * b[i];
        LL vm = max(0LL, (v / _lcm - 1) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        dout << vm;
        cnt += vm;
        LL val = max(0LL, v / _lcm - 1) * _lcm, ms = LLONG_MAX >> 1;
        for (LL j = 0; (j - 1) * a[i] <= v - val; ++j) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] + !!((v - val - j * a[i]) % b[i])) * q[i]));
        }
        dout << '\n' << v << ',' << i << ':' << vm << ' ' << ms << ' ' << vm + ms << '\n';
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
    LL l = 0, r = UINT_MAX >> 1;
    while (l + 1 < r) {
        LL mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
        dout << '\n';
    }
    cout << l;
    return 0;
}