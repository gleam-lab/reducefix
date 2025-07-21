#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_min_cost(ll a, ll b, ll p, ll q, ll items) {
    if (items == 0) return 0;
    
    // We need to find minimum cost to produce exactly 'items' using a (cost p) and b (cost q)
    // This is an unbounded knapsack problem
    ll max_possible = items + max(a, b);
    vector<ll> dp(max_possible + 1, LLONG_MAX);
    dp[0] = 0;
    
    for (ll i = 1; i <= max_possible; ++i) {
        if (i >= a && dp[i - a] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - a] + p);
        }
        if (i >= b && dp[i - b] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - b] + q);
        }
    }
    
    // Find the minimal cost for >= items
    ll min_cost = LLONG_MAX;
    for (ll i = items; i <= max_possible; ++i) {
        if (dp[i] < min_cost) {
            min_cost = dp[i];
        }
    }
    
    return min_cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    ll left = 0, right = 1e10;
    ll answer = 0;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            ll cost = calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost == LLONG_MAX) { // Not possible to produce mid items for this method
                total_cost = x + 1;
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