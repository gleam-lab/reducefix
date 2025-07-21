#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll x) {
    // DP to find minimal cost to produce x widgets using given methods
    vector<ll> dp(x + 1, LLONG_MAX);
    dp[0] = 0;
    
    for (ll i = 1; i <= x; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0, high = 1e18;
    ll best = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            ll cost = compute_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost == LLONG_MAX) {
                total_cost = LLONG_MAX;
                break;
            }
            total_cost += cost;
            if (total_cost > x) break;
        }
        
        if (total_cost <= x) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << best << endl;
    return 0;
}