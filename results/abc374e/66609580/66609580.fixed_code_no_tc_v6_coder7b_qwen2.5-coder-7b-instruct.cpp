#include <bits/stdc++.h>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl

const int N = 110;
long long a[N], b[N], p[N], q[N];
long long n, x;

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
        long long lcm = a[i] / gcd(a[i], b[i]) * b[i];
        long long vm = max(0LL, (v / lcm - 1) * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i])));
        dout(vm);
        cnt += vm;
        long long val = max(0LL, v / lcm - 1) * lcm, ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; ++j) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] +
                !!((v - val - j * a[i]) % b[i])) * q[i]));
        }
        dout('\n' << v << ',' << i << ':' << vm << ' ' << ms << ' ' << vm + ms << '\n');
        cnt += ms;
        if (cnt > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = UINT_MAX;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}