#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int n;
ll a[110], b[110], p[110], q[110], x;

inline ll lcm(ll x, ll y) {
    return x / __gcd(x, y) * y;
}

inline bool check(ll v) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll l = lcm(a[i], b[i]);
        
        // Full cycles contribution
        ll full_cycles = max(0LL, (v - 1) / l);
        ll per_cycle_cost = min(p[i] * (l / a[i]), q[i] * (l / b[i]));
        cnt += full_cycles * per_cycle_cost;
        if (cnt > x) return false;
        
        // Remaining part after full cycles
        ll rem = v % l;
        if (rem == 0) rem = l;
        
        ll min_cost = INF;
        for (ll j = 0; j * a[i] <= rem; j++) {
            ll cost_a = j * p[i];
            ll remaining = rem - j * a[i];
            ll k = (remaining + b[i] - 1) / b[i];
            ll cost_b = k * q[i];
            min_cost = min(min_cost, cost_a + cost_b);
        }
        
        cnt += min_cost;
        if (cnt > x) return false;
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
    
    ll l = 0, r = 2e14;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1;
}