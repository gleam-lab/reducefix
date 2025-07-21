#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll compute_cost(ll a, ll b, ll p, ll q, ll x) {
    // Compute the minimal cost to produce x items using the two options
    ll min_cost = LLONG_MAX;
    // Try all possible k where k is the number of times we use option a
    // The maximum k is when we use option a as much as possible (x/a)
    ll max_k = x / a + 2;
    for (ll k = 0; k <= max_k; ++k) {
        ll remaining = x - k * a;
        if (remaining < 0) continue;
        ll l = (remaining + b - 1) / b;  // ceil(remaining / b)
        if (l < 0) continue;
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
        bool possible = true;
        rep(i,n) {
            ll cost = compute_cost(a[i], b[i], p[i], q[i], mid);
            if (cost > x - total_cost) {
                possible = false;
                break;
            }
            total_cost += cost;
        }
        if (possible) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}