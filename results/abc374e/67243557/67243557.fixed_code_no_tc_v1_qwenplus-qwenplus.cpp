#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// Computes the minimal cost to buy at least 'x' candies of type (a, p) and (b, q)
ll compute_min_cost(ll a, ll b, ll p, ll q, ll x) {
    // dp[i] = min cost to get i candies
    vector<ll> dp(x + 1, 1e18);
    dp[0] = 0;
    
    for (int i = 0; i <= x; ++i) {
        if (i + a <= x) dp[i + a] = min(dp[i + a], dp[i] + p);
        if (i + b <= x) dp[i + b] = min(dp[i + b], dp[i] + q);
    }
    
    // Return minimum cost to get at least x candies
    return *min_element(dp.begin() + x, dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    vector<ll> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    // Binary search on maximum number of candies we can buy
    ll low = 0, high = 1e18, ans = 0;
    
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        ll total_cost = 0;
        
        rep(i, n) {
            total_cost += compute_min_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break; // Early exit if already exceeded budget
        }
        
        if (total_cost <= x) low = mid;
        else high = mid - 1;
    }
    
    cout << low << '\n';
    return 0;
}