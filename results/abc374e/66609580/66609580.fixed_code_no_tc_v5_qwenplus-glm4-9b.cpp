#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

inline long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

inline long long calculateVM(long long v, long long lcm_value, long long a_index, long long b_index) {
    return (v / lcm_value - 1) * min(p[a_index] * (lcm_value / a[a_index]), q[b_index] * (lcm_value / b[b_index]));
}

inline long long calculateMS(long long v, long long lcm_value, long long a_index, long long b_index) {
    long long val = max(0LL, v / lcm_value - 1) * lcm_value, ms = LLONG_MAX >> 1;
    long long j = 0;
    while ((j - 1) * a[a_index] <= v - val) {
        ms = min(ms, j * p[a_index] + max(0LL, ((v - val - j * a[a_index]) / b[b_index] + 
            (v - val - j * a[a_index]) % b[b_index] != 0) * q[b_index]));
        j++;
    }
    return ms;
}

bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long lcm_value = lcm(a[i], b[i]);
        long long vm = calculateVM(v, lcm_value, i, i);
        cnt += vm;

        long long ms = calculateMS(v, lcm_value, i, i);
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
    long long l = 0, r = (1LL << 40);
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}