#include <bits/stdc++.h>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long gcd_ab = __gcd(a[i], b[i]);
        long long lcm_ab = a[i] / gcd_ab * b[i];
        long long full_cycles = v / lcm_ab;
        long long remaining = v % lcm_ab;

        long long min_cost = LLONG_MAX;
        for (long long k = 0; k <= full_cycles; ++k) {
            long long remaining_v = v - k * lcm_ab;
            long long max_j = remaining_v / a[i];
            for (long long j = 0; j <= max_j; ++j) {
                long long remaining_after_j = remaining_v - j * a[i];
                long long m = (remaining_after_j + b[i] - 1) / b[i]; // ceiling division
                long long cost = k * min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i])) + j * p[i] + m * q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
        }
        total += min_cost;
        if (total > x) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long left = 0;
    long long right = 1LL << 60;
    long long answer = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}