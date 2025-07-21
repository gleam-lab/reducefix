#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(...) // uncomment to enable debugging

int n;
ll a[110], b[110], p[110], q[110], x;

inline bool check(ll v) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ll g = gcd(a[i], b[i]);
        ll lcm = a[i] / g * b[i];
        
        // Count full LCM blocks
        ll full_blocks = v / lcm;
        ll cost_per_block = min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i]));
        ll total_full_cost = full_blocks * cost_per_block;
        cnt += total_full_cost;

        if (cnt > x) return false;

        // Remaining part after full blocks
        ll remaining = v % lcm;
        ll min_remaining_cost = numeric_limits<ll>::max();

        // Try all possible a[i] usages up to remaining
        for (ll j = 0; ; ++j) {
            ll used_a = j * a[i];
            if (used_a > remaining) break;
            ll rem = remaining - used_a;
            ll k = rem / b[i];
            if (rem % b[i]) k++;
            ll total_cost = j * p[i] + k * q[i];
            min_remaining_cost = min(min_remaining_cost, total_cost);
        }

        cnt += min_remaining_cost;
        if (cnt > x) return false;
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

    ll l = 0, r = 2e18;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
}