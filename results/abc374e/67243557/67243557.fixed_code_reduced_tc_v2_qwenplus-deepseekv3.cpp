#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(ll a, ll b, ll p, ll q, ll x) {
    const ll INF = 1e18;
    vector<ll> dp(x+1, INF);
    dp[0] = 0;
    
    for (ll i = 1; i <= x; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i-a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i-b] + q);
    }
    
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll l = 0, r = 1;
    // First find a suitable upper bound
    while (true) {
        ll total = 0;
        rep(i,n) {
            total += f(a[i], b[i], p[i], q[i], r);
            if (total > x) break;
        }
        if (total > x) break;
        if (r > 1e18 / 2) {  // Prevent overflow
            r = 1e18;
            break;
        }
        r *= 2;
    }
    
    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll total = 0;
        rep(i,n) {
            total += f(a[i], b[i], p[i], q[i], mid);
            if (total > x) break;
        }
        if (total <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans;
    return 0;
}