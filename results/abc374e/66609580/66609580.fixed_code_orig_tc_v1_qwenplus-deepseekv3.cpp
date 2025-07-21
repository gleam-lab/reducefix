#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll x;
ll a[110], b[110], p[110], q[110];

bool check(ll v) {
    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        ll lcm = a[i] / __gcd(a[i], b[i]) * b[i];
        ll full_cycles = v / lcm;
        ll remaining = v % lcm;
        
        // Cost for full cycles
        ll cost_full = full_cycles * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i]));
        
        // Cost for remaining time
        ll min_cost = LLONG_MAX;
        ll max_a = remaining / a[i] + 1;
        for (ll k = 0; k <= max_a; ++k) {
            ll time_a = k * a[i];
            if (time_a > remaining) break;
            ll time_b = remaining - time_a;
            ll cnt_b = (time_b + b[i] - 1) / b[i];  // ceil(time_b / b[i])
            min_cost = min(min_cost, k * p[i] + cnt_b * q[i]);
        }
        
        total += cost_full + min_cost;
        if (total > x) return false;
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
    
    ll low = 0, high = 1e18;
    while (low < high) {
        ll mid = low + (high - low + 1) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    cout << low << '\n';
    return 0;
}