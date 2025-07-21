#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x;
ll a[110], b[110], p[110], q[110];

bool check(ll v) {
    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        ll g = __gcd(a[i], b[i]);
        ll lcm = a[i] / g * b[i];
        
        // Calculate full cycles
        ll full_cycles = v / lcm;
        ll full_contribution = min(full_cycles * p[i] * (lcm / a[i]), 
                                  full_cycles * q[i] * (lcm / b[i]));
        
        // Calculate remaining time after full cycles
        ll remaining = v % lcm;
        ll min_remaining = LLONG_MAX;
        
        // Try all possible a-counts for remaining time
        ll max_a = remaining / a[i] + 2; // Small buffer
        for (ll cnt_a = 0; cnt_a <= max_a; ++cnt_a) {
            ll time_a = cnt_a * a[i];
            if (time_a > remaining) break;
            
            ll time_b = remaining - time_a;
            ll cnt_b = (time_b + b[i] - 1) / b[i]; // Ceiling division
            
            ll cost = cnt_a * p[i] + cnt_b * q[i];
            min_remaining = min(min_remaining, cost);
        }
        
        total += full_contribution + min_remaining;
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