#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(n);i++)
using ll = long long;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll target) {
    // Use a bounded DP with periodic optimization
    ll period = lcm(a, b);
    vector<ll> dp(period + 1, 1e18);
    dp[0] = 0;
    
    for (ll i = 0; i <= period; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    
    // Improve from left and right to ensure min values propagate
    for (ll i = 1; i <= period; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 0); // No extra cost for "carry forward"
    }
    for (ll i = period - 1; i >= 0; --i) {
        dp[i] = min(dp[i], dp[i + 1]);
    }

    ll full_cycles = target / period;
    ll remainder = target % period;
    
    return full_cycles * dp[period] + dp[remainder];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    vector<ll> a(n), b(n), p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search on the number of candies we can buy
    ll low = 0, high = 1e14; // High enough upper bound
    ll answer = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            total_cost += compute_min_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break; // Early exit if already over budget
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