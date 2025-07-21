#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int n;
ll a[110], b[110], p[110], q[110], x;

inline ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

bool check(ll v) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ll g = gcd(a[i], b[i]);
        ll l = lcm(a[i], b[i]);
        
        // Full cycles
        ll full_cycles = max(0LL, (v / l) - 1);
        ll contrib = full_cycles * min(p[i] * (l / a[i]), q[i] * (l / b[i]));
        cnt += contrib;
        
        if (cnt >= x) return false;
        
        // Remaining part after full cycles
        ll rem = v - full_cycles * l;
        
        ll best = INF;
        for (ll j = 0; ; ++j) {
            ll cost_a = j * a[i];
            if (cost_a > rem) break;
            ll need_b = (rem - cost_a + b[i] - 1) / b[i];
            ll total_cost = j * p[i] + need_b * q[i];
            best = min(best, total_cost);
        }
        
        cnt += best;
        if (cnt >= x) return false;
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
    
    ll l = 0, r = 1e14;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    cout << (check(l) ? l : l - 1);
}