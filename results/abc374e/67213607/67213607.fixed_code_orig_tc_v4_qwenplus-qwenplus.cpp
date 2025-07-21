#include <bits/stdc++.h>
using namespace std;

int n;
long long x;
long long a[105], p[105], b[105], q[105];

// Function to compute ceiling of division
inline long long ceil_div(long long num, long long den) {
    return (num + den - 1) / den;
}

bool can_build(long long target) {
    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        long long min_cost = LLONG_MAX;
        // Try all reasonable numbers of A items
        long long max_a_used = min((long long)1e6, ceil_div(target, a[i]));
        for (long long j = 0; j <= max_a_used; ++j) {
            long long have = j * a[i];
            if (have >= target) {
                min_cost = min(min_cost, j * p[i]);
                continue;
            }
            long long need_b = ceil_div(target - have, b[i]);
            min_cost = min(min_cost, j * p[i] + need_b * q[i]);
        }

        // Try all reasonable numbers of B items
        long long max_b_used = min((long long)1e6, ceil_div(target, b[i]));
        for (long long j = 0; j <= max_b_used; ++j) {
            long long have = j * b[i];
            if (have >= target) {
                min_cost = min(min_cost, j * q[i]);
                continue;
            }
            long long need_a = ceil_div(target - have, a[i]);
            min_cost = min(min_cost, j * q[i] + need_a * p[i]);
        }

        total_cost += min_cost;
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    long long l = 0, r = 1000000000;
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (can_build(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}