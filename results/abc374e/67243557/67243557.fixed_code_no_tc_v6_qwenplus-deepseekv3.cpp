#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_min_cost(ll a, ll b, ll p, ll q, ll x) {
    // dp[i] = min cost to produce exactly i items
    vector<ll> dp(x + 1, LLONG_MAX);
    dp[0] = 0;
    
    for (ll i = 1; i <= x; ++i) {
        if (i >= a && dp[i - a] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - a] + p);
        }
        if (i >= b && dp[i - b] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - b] + q);
        }
    }
    
    // Handle cases where we might need to produce more than x items
    // to get optimal cost (since we can buy in bulk)
    for (ll i = x - 1; i >= 0; --i) {
        dp[i] = min(dp[i], dp[i + 1]);
    }
    
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0, high = 2e18; // Upper bound needs to be large enough
    ll answer = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        bool feasible = true;
        
        for (int i = 0; i < n; ++i) {
            ll cost = calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost == LLONG_MAX) {
                feasible = false;
                break;
            }
            total_cost += cost;
            if (total_cost > x) {
                feasible = false;
                break;
            }
        }
        
        if (feasible) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}