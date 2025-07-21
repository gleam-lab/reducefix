#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
    // DP[i] = minimum cost to buy i items
    vector<ll> dp(2 * max(a, b) + 10, 1e18);
    dp[0] = 0;
    
    // Fill forward
    for (int i = 1; i < (int)dp.size(); ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    
    // Find cycle properties
    ll cycle_len = a * b;
    ll prefix_min = 1e18;
    ll base_cost = 0;
    
    // Precompute the minimum cost per item in the cycle
    vector<ll> cycle;
    for (int i = 0; i < cycle_len; ++i) {
        prefix_min = min(prefix_min, dp[i]);
        cycle.push_back(prefix_min);
    }

    // Total number of full cycles and remaining items
    ll full_cycles = x / cycle_len;
    ll remainder = x % cycle_len;

    return full_cycles * cycle_len * cycle[0] + accumulate(cycle.begin(), cycle.begin() + remainder, 0LL);
}

// Optimized binary search upper bound
ll binary_search_upper_bound(ll n, ll x, const vector<ll>& a, const vector<ll>& p, const vector<ll>& b, const vector<ll>& q) {
    ll low = 0, high = 1e18;
    ll result = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n && total_cost <= x; ++i) {
            total_cost += f(a[i], b[i], p[i], q[i], mid);
        }
        
        if (total_cost <= x) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll x;
    cin >> n >> x;
    
    vector<ll> a(n), b(n), p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    // Binary search for maximum total snacks we can buy
    ll low = 0, high = 1e18;
    ll ans = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            // Compute minimal cost to buy 'mid' snacks from machine i
            vector<ll> dp(2 * max(a[i], b[i]) + 10, 1e18);
            dp[0] = 0;
            
            for (int j = 1; j < (int)dp.size(); ++j) {
                if (j >= a[i]) dp[j] = min(dp[j], dp[j - a[i]] + p[i]);
                if (j >= b[i]) dp[j] = min(dp[j], dp[j - b[i]] + q[i]);
            }
            
            ll cycle_len = a[i] * b[i];
            ll prefix_min = 1e18;
            vector<ll> cycle;
            
            for (int j = 0; j < cycle_len; ++j) {
                prefix_min = min(prefix_min, dp[j]);
                cycle.push_back(prefix_min);
            }
            
            ll full_cycles = mid / cycle_len;
            ll rem = mid % cycle_len;
            
            ll cost = full_cycles * cycle_len * cycle[0];
            for (int j = 0; j < rem; ++j) {
                cost += cycle[j];
            }
            
            total_cost += cost;
            if (total_cost > x) break;
        }
        
        if (total_cost <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}