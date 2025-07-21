#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_min_cost(ll a, ll b, ll p, ll q, ll x) {
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
    
    // Fill in any remaining gaps (in case we couldn't reach some numbers)
    for (ll i = 1; i <= x; ++i) {
        if (dp[i] == LLONG_MAX) {
            dp[i] = dp[i - 1];
        }
    }
    
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll left = 0, right = 1e18;
    ll answer = 0;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            ll cost = calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost == LLONG_MAX) {
                total_cost = LLONG_MAX;
                break;
            }
            total_cost += cost;
            if (total_cost > x) break;
        }
        
        if (total_cost <= x) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}