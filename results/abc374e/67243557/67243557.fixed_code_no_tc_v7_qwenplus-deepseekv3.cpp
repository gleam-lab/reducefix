#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

const ll INF = 1e18;

ll f(ll a, ll b, ll p, ll q, ll x) {
    vector<ll> dp(x + 1, INF);
    dp[0] = 0;
    for (ll i = 1; i <= x; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll total_cost = 0;
        bool possible = true;
        
        for (int i = 0; i < n; ++i) {
            ll cost = f(a[i], b[i], p[i], q[i], mid);
            if (cost == INF) {
                possible = false;
                break;
            }
            total_cost += cost;
            
            if (total_cost > x) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    cout << l << endl;
    return 0;
}