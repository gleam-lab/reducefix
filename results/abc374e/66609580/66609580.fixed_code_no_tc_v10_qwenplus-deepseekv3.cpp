#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x;
ll a[110], b[110], p[110], q[110];

bool check(ll v) {
    ll total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        ll lcm_ab = a[i] / __gcd(a[i], b[i]) * b[i];
        ll full_cycles = v / lcm_ab;
        ll remaining = v % lcm_ab;
        
        // Cost for full cycles
        ll cost_full = full_cycles * min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i]));
        
        // Cost for remaining time
        ll min_remaining = LLONG_MAX;
        ll max_a = remaining / a[i] + 1;
        for (ll k = 0; k <= max_a; ++k) {
            ll time_a = k * a[i];
            if (time_a > remaining) break;
            ll time_b = remaining - time_a;
            ll cnt_b = (time_b + b[i] - 1) / b[i];  // ceiling division
            min_remaining = min(min_remaining, k * p[i] + cnt_b * q[i]);
        }
        
        total_cost += cost_full + min_remaining;
        if (total_cost > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    ll left = 0, right = 1e18;
    while (left < right) {
        ll mid = left + (right - left + 1) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    cout << left << '\n';
    return 0;
}