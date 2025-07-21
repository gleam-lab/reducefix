#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x;
ll a[110], b[110], p[110], q[110];

bool check(ll v) {
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        ll lcm = a[i] / __gcd(a[i], b[i]) * b[i];
        ll full_cycles = v / lcm;
        ll remaining = v % lcm;
        
        // Calculate cost for full cycles
        ll cost_full = min(full_cycles * p[i] * (lcm / a[i]), 
                          full_cycles * q[i] * (lcm / b[i]));
        
        // Calculate cost for remaining time
        ll min_remaining = LLONG_MAX;
        for (ll j = 0; j * a[i] <= remaining; j++) {
            ll k = max(0LL, (remaining - j * a[i] + b[i] - 1) / b[i]);
            min_remaining = min(min_remaining, j * p[i] + k * q[i]);
        }
        
        total += cost_full + min_remaining;
        if (total > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    cout << l << '\n';
    return 0;
}