#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> a, b, p, q;

inline long long gcd(long long x, long long y) {
    while (y != 0) {
        long long t = y;
        y = x % y;
        x = t;
    }
    return x;
}

long long lcm(long long x, long long y) {
    return x / gcd(x, y) * y;
}

bool check(long long v) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        long long lcm_ab = lcm(a[i], b[i]);
        long long vm = (v / lcm_ab - 1) * min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i]));
        cnt += vm;
        long long val = (v / lcm_ab - 1) * lcm_ab;
        long long ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; j++) {
            long long cost = j * p[i] + max(0LL, (v - val - j * a[i]) / b[i] + ((v - val - j * a[i]) % b[i] != 0) * q[i]);
            ms = min(ms, cost);
        }
        cnt += ms;
        if (cnt > v) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n + 1), b.resize(n + 1), p.resize(n + 1), q.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = 2e18;  // Assuming x can be as large as 2e18
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}