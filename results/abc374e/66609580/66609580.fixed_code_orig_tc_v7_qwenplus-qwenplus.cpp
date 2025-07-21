#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x;
ll a[110], b[110], p[110], q[110];

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

bool check(ll val) {
    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        ll LCM = lcm(a[i], b[i]);
        ll full_cycles = val / LCM;
        ll rem = val % LCM;

        // Calculate the cost for full cycles
        ll cost_per_cycle = min(p[i] * (LCM / a[i]), q[i] * (LCM / b[i]));
        ll full_cost = full_cycles * cost_per_cycle;
        total += full_cost;

        if (total > x) return false;

        // Now handle the remainder part after full cycles
        ll min_remainder_cost = numeric_limits<ll>::max();

        // Try all possible number of A uses in the remainder
        for (ll cntA = 0; ; ++cntA) {
            ll costA = cntA * p[i];
            ll remaining_length = val - cntA * a[i];
            if (remaining_length < 0) break;

            ll cntB = (remaining_length + b[i] - 1) / b[i];
            ll costB = cntB * q[i];

            min_remainder_cost = min(min_remainder_cost, costA + costB);

            // Optimization: since we're trying to minimize cost, once the costA starts increasing past current minimum significantly, we can break
            if (costA >= min_remainder_cost) break;
        }

        total += min_remainder_cost;

        if (total > x) return false;
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

    ll low = 0, high = 2e18;
    while (low < high) {
        ll mid = (low + high) >> 1;
        if (check(mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low - 1 << "\n";
}