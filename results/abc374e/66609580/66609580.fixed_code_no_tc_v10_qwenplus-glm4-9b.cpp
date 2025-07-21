#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long lcm = a[i] / gcd(a[i], b[i]) * b[i];
        long long vm = (v / lcm - 1) * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i]));
        cnt += vm;
        long long val = (v / lcm - 1) * lcm;
        long long ms = LLONG_MAX >> 1;
        for (long long j = 0; j * a[i] <= v - val; j++) {
            long long rem = v - val - j * a[i];
            long long add = (rem / b[i] + (rem % b[i] != 0)) * q[i];
            ms = min(ms, j * p[i] + add);
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
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = LLONG_MAX;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}