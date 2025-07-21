#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int MAXN = 110;
long long a[MAXN], b[MAXN], p[MAXN], q[MAXN], x;

int gcd(long long a, long long b) {
    return a == 0 ? b : gcd(b % a, a);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        long long lcm_ab = lcm(a[i], b[i]);
        long long val = max(0LL, (v / lcm_ab - 1) * min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i])));
        cnt += val;
        if (cnt > x) return false;
    }
    for (int i = 1; i <= n; ++i) {
        long long lcm_ab = lcm(a[i], b[i]);
        long long max_lcm_val = max(0LL, v / lcm_ab - 1) * lcm_ab;
        long long ms = LLONG_MAX >> 1;
        long long j = 1;
        while (j * a[i] <= v - max_lcm_val) {
            long long next_lcm_val = max_lcm_val + j * a[i];
            long long remaining = v - next_lcm_val;
            if (remaining % b[i] == 0) {
                long long div = remaining / b[i];
                ms = min(ms, j * p[i] + div * q[i]);
            }
            j++;
        }
        cnt += ms;
        if (cnt > x) return false;
    }
    return true;
}

int main() {
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long left = 0, right = (long long)(1e18);
    while (left < right) {
        long long mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left;
    return 0;
}