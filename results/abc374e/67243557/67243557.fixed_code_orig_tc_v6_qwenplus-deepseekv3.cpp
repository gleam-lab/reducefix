#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(ll a, ll b, ll p, ll q, ll w) {
    ll max_amount = w + 1;
    vector<ll> dp(max_amount, LLONG_MAX);
    dp[0] = 0;
    for (ll i = 1; i < max_amount; ++i) {
        if (i >= a && dp[i - a] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - a] + p);
        }
        if (i >= b && dp[i - b] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - b] + q);
        }
    }
    return dp[w];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0;
    ll high = 10000000000LL;
    ll best = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        bool feasible = true;
        
        for (int i = 0; i < n; ++i) {
            ll cost = f(a[i], b[i], p[i], q[i], mid);
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
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << best << endl;
    return 0;
}