#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_min_cost(ll a, ll b, ll p, ll q, ll x) {
    if (a == b) {
        ll cost_per_item = min(p, q);
        return x * cost_per_item;
    }
    
    ll min_cost = numeric_limits<ll>::max();
    // We need to find the optimal combination of a and b purchases
    // Since x can be large, we can't compute all possibilities, but we can find the minimal
    // cost by considering up to b possibilities for one variable and a for the other
    
    // Try all possible counts of a-items (0 to min(x/a, b))
    ll max_a = min(x / a, b);
    for (ll k = 0; k <= max_a; ++k) {
        ll remaining = x - k * a;
        if (remaining < 0) continue;
        ll l = remaining / b;
        ll cost = k * p + l * q;
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    
    // Also try all possible counts of b-items (0 to min(x/b, a))
    ll max_b = min(x / b, a);
    for (ll l = 0; l <= max_b; ++l) {
        ll remaining = x - l * b;
        if (remaining < 0) continue;
        ll k = remaining / a;
        ll cost = k * p + l * q;
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    
    return min_cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0, high = 1e18;
    ll answer = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            total_cost += calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break;  // Early termination if already over budget
        }
        
        if (total_cost <= x) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}