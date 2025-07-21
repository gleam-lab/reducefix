#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x;
ll a[110], b[110], p[110], q[110];

bool check(ll v) {
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        ll g = __gcd(a[i], b[i]);
        ll lcm = a[i] / g * b[i];
        
        ll full_cycles = v / lcm;
        ll remaining = v % lcm;
        
        ll full_cost = min(full_cycles * (lcm / a[i]) * p[i], 
                          full_cycles * (lcm / b[i]) * q[i]);
        
        ll best_remaining = LLONG_MAX;
        ll max_a = remaining / a[i] + 2;
        for (ll k = 0; k <= max_a; k++) {
            ll a_count = k;
            ll remaining_time = remaining - a_count * a[i];
            if (remaining_time < 0) continue;
            ll b_count = remaining_time / b[i];
            if (remaining_time % b[i] != 0) b_count++;
            ll cost = a_count * p[i] + b_count * q[i];
            if (cost < best_remaining) best_remaining = cost;
            if (best_remaining == 0) break;
        }
        
        total += full_cost + best_remaining;
        if (total > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    ll low = 0, high = 1LL << 60;
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << endl;
    return 0;
}