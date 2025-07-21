#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// Function to compute the minimum cost to buy x items using two types of packs
ll f(ll a, ll b, ll p, ll q, ll x) {
    // dp[i] = minimum cost to buy i items
    vector<ll> dp(2 * (a + b), 1e18);
    dp[0] = 0;

    for (ll i = 0; i < 2 * (a + b); ++i) {
        if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
        if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
    }

    // Precompute prefix minimums
    for (ll i = 1; i < 2 * (a + b); ++i) {
        dp[i] = min(dp[i], dp[i - 1]);
    }

    ll period = a * b;  // LCM(a, b) as an upper bound for repeating pattern
    if (period > 2000) period = 2000;  // Limit period size to avoid issues

    // Find how much it costs to buy 'period' items
    ll cost_per_period = dp[period];

    // Compute how many full periods we have in x
    ll full_periods = x / cost_per_period;
    ll remaining_money = x % cost_per_period;

    // How many items can we buy in remaining money?
    ll items_from_remaining = 0;
    while (items_from_remaining + 1 <= period && dp[items_from_remaining + 1] <= remaining_money) {
        ++items_from_remaining;
    }

    return full_periods * period + items_from_remaining;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    vector<int> a(n), b(n), p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    // Binary search on the answer
    ll low = 0, high = 1e14;  // We use a large enough upper bound
    ll answer = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            ll cost = f(a[i], b[i], p[i], q[i], mid);
            total_cost += cost;
            if (total_cost > x) break;  // Early stopping if already over budget
        }
        
        if (total_cost <= x) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << answer << "\n";
    return 0;
}