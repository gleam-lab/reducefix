#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, long long>> a, b;
    for (int i = 0; i <= n; ++i) {
        long long ai, bi, pi, qi;
        cin >> ai >> pi >> bi >> qi;
        a.push_back({ai, pi});
        b.push_back({bi, qi});
    }

    long long l = 0, r = 1e18;
    while (l + 1 < r) {
        long long mid = (l + r + 1) / 2;
        long long cnt = 0, vm = 0, ms = 0, val = 0;
        for (int i = 0; i <= n; ++i) {
            long long _lcm = lcm(a[i].first, b[i].first);
            long long vm_i = max(0LL, (mid / _lcm - 1) * min(a[i].second * (_lcm / a[i].first), b[i].second * (_lcm / b[i].first)));
            cnt += vm_i;
            val = max(0LL, mid / _lcm - 1) * _lcm;
            ms = LLONG_MAX >> 1;
            long long j = 0;
            while (j * a[i].first <= mid - val) {
                ms = min(ms, j * a[i].second + max(0LL, ((mid - val - j * a[i].first) / b[i].first + 
                    !!((mid - val - j * a[i].first) % b[i].first)) * b[i].second);
                j++;
            }
            cnt += ms;
            if (cnt > x) break;
        }
        cout << '\n';
        if (cnt > x) r = mid;
        else l = mid;
    }

    cout << l;
    return 0;
}