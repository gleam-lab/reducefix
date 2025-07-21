#include <bits/stdc++.h>
using namespace std;
#define dout if(0)cerr

int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long g = __gcd(a[i], b[i]);
        __int128 _lcm = (__int128)a[i] / g * b[i];
        
        // Full LCM blocks
        long long num_blocks = max(0LL, (long long)(_lcm ? v / _lcm : 0) - 1);
        if (num_blocks > 0) {
            __int128 cost_per_block_a = p[i] * (_lcm / a[i]);
            __int128 cost_per_block_b = q[i] * (_lcm / b[i]);
            __int128 total_cost_per_block = min(cost_per_block_a, cost_per_block_b);
            cnt += (__int128)num_blocks * total_cost_per_block;
            if (cnt > x) return false;
        }

        // Remaining part after full blocks
        long long val = num_blocks * _lcm;
        long long rem = v - val;
        if (rem < 0) rem = 0;

        long long best = LLONG_MAX;
        for (long long j = 0; j * a[i] <= rem || (j == 0); j++) {
            long long remaining_after_a = rem - j * a[i];
            if (remaining_after_a < 0) break;

            long long k = max(0LL, (remaining_after_a / b[i]) + !!(remaining_after_a % b[i]));
            long long total_cost = j * p[i] + k * q[i];
            best = min(best, total_cost);
            if (best == 0) break;
        }
        cnt += best;
        if (cnt > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    long long l = 0, r = 2e18;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}