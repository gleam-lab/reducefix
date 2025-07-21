#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        long long lcm_value = lcm(a[i], b[i]);
        long long vm = (v / lcm_value - 1) * min(p[i] * (lcm_value / a[i]), q[i] * (lcm_value / b[i]));
        cnt += vm;
        if (cnt > x) return false;
        
        long long val = (v / lcm_value - 1) * lcm_value;
        long long ms = LLONG_MAX >> 1;
        long long j = 0;
        while ((j - 1) * a[i] <= v - val) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] + 
                                               !!((v - val - j * a[i]) % b[i])) * q[i]));
            j++;
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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = 2e18;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}