#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int n;
ll a[110], b[110], p[110], q[110], x;

inline bool check(ll v) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll g = __gcd(a[i], b[i]);
        ll lcm = a[i] / g * b[i];
        
        // First part: full cycles
        ll full_cycles = v / lcm;
        ll cost_full = full_cycles * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i]));
        cnt += cost_full;
        
        if (cnt >= x) return false;
        
        // Second part: partial cycle
        ll remaining = v % lcm;
        ll min_cost = INF;
        
        // Try different numbers of item A within this partial cycle
        for (ll j = 0; j * a[i] <= remaining; j++) {
            ll cost_a = j * p[i];
            ll remaining_after_a = remaining - j * a[i];
            ll need_b = (remaining_after_a + b[i] - 1) / b[i];
            ll cost_b = need_b * q[i];
            min_cost = min(min_cost, cost_a + cost_b);
            
            if (min_cost >= x - cnt) break; // Early exit if already enough
        }
        
        cnt += min_cost;
        if (cnt >= x) return false;
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
    
    ll l = 0, r = 2e14; // Safe upper bound
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    
    cout << (l - 1);
}