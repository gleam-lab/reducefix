#include <bits/stdc++.h>
using namespace std;

#define dout if(false) cout

bool check(long long v, vector<long long>& a, vector<long long>& p, vector<long long>& b, vector<long long>& q, long long x) {
    int n = a.size();
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        long long _lcm = a[i] / __gcd(a[i], b[i]) * b[i];
        long long vm = max(0LL, (v / _lcm - 1) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        dout << vm;
        cnt += vm;
        long long val = max(0LL, v / _lcm - 1) * _lcm, ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; ++j) {
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

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = UINT_MAX;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (check(mid, a, p, b, q, x)) {
            l = mid + 1;
        } else {
            r = mid;
        }
        dout << '\n';
    }

    cout << l - 1 << '\n';

    return 0;
}