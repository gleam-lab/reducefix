#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int n;
ll a[110], b[110], p[110], q[110], x;

inline ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

inline bool check(ll v) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ll g = gcd(a[i], b[i]);
        ll L = a[i] / g * b[i];
        
        // Full blocks
        ll full_blocks = v / L;
        ll cost_full = full_blocks * min(p[i] * (L / a[i]), q[i] * (L / b[i]));
        cnt += cost_full;
        
        if (cnt > x) return false;
        
        // Partial block
        ll remaining = v % L;
        ll min_cost = INF;
        
        for (ll j = 0; j * a[i] <= remaining; ++j) {
            ll rem = remaining - j * a[i];
            ll k = (rem + b[i] - 1) / b[i]; // ceil division
            if (k < 0) k = 0;
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        
        cnt += min_cost;
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
    
    ll l = 0, r = 2e14;
    while (l + 1 < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    
    cout << l << '\n';
}