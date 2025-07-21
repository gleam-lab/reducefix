#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

#define dout if (false) cerr

bool check(const vector<long long>& a, const vector<long long>& p, const vector<long long>& b, const vector<long long>& q, long long v, long long x) {
    long long cnt = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        long long _lcm = a[i] / gcd(a[i], b[i]) * b[i];
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = INT_MAX;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (check(a, p, b, q, mid, x)) l = mid;
        else r = mid;
    }

    cout << l << endl;
    return 0;
}