#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll x) {
    // DP array to store minimum cost to produce i items
    vector<ll> dp(10010, LLONG_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= min(x, 10009LL); ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i-a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i-b] + q);
    }
    
    // Fill any remaining gaps due to the step sizes
    for (int i = min(x, 10009LL) - 1; i > 0; --i) {
        dp[i] = min(dp[i], dp[i+1]);
    }
    
    ll tt = a * b;
    ll t = x / tt;
    ll remainder = x % tt;
    
    // Handle cases where the cost might overflow
    if (t > 0 && dp[tt] > LLONG_MAX / t) {
        return LLONG_MAX;
    }
    
    ll total = t * dp[tt] + (remainder > 0 ? dp[remainder] : 0);
    return min(total, LLONG_MAX);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0, high = 10000000000;
    ll answer = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        bool feasible = true;
        
        for (int i = 0; i < n; ++i) {
            ll cost = compute_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost > x - total_cost) {
                feasible = false;
                break;
            }
            total_cost += cost;
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