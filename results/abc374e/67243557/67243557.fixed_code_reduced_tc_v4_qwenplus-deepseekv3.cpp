#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll calculate_cost(ll a, ll b, ll p, ll q, ll x) {
    // dp[i] = minimum cost to produce i items
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
    
    // Handle cases where we might need to produce more than x to get x
    // by taking the minimum of all dp[k] where k >= x
    ll min_cost = dp[x];
    for (ll k = x + 1; k <= min(x + max(a, b), 10000LL); ++k) {
        if (dp[k] != LLONG_MAX) {
            min_cost = min(min_cost, dp[k]);
        }
    }
    
    return min_cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0, high = 1e18;
    ll answer = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            ll cost = calculate_cost(a[i], b[i], p[i], q[i], mid);
            if (cost == LLONG_MAX) {
                total_cost = LLONG_MAX;
                break;
            }
            total_cost += cost;
            if (total_cost > x) {
                break;
            }
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