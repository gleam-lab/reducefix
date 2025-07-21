#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x;
ll a[110], b[110], p[110], q[110];

// Helper to compute GCD
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool check(ll time_limit) {
    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        ll g = gcd(a[i], b[i]);
        ll lcm = a[i] / g * b[i];

        // Full cycles of LCM where both can be produced optimally
        ll full_cycles = time_limit / lcm;
        ll rem = time_limit % lcm;

        // Cost per full cycle
        ll cost_a_per_cycle = p[i] * (lcm / a[i]);
        ll cost_b_per_cycle = q[i] * (lcm / b[i]);
        ll min_cost_per_cycle = min(cost_a_per_cycle, cost_b_per_cycle);

        // Contribution from full cycles
        total += full_cycles * min_cost_per_cycle;

        if (total > x) return false;

        // Now try all combinations in the remaining time (rem)
        ll min_cost = LLONG_MAX;
        for (ll na = 0; na * a[i] <= rem; ++na) {
            ll remaining_time = rem - na * a[i];
            ll nb = remaining_time / b[i] + (remaining_time % b[i] ? 1 : 0);
            ll cost = na * p[i] + max(0LL, nb) * q[i];
            min_cost = min(min_cost, cost);
        }

        total += min_cost;
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

    ll left = 0, right = 2e18;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    cout << (check(left) ? left : left - 1);
}