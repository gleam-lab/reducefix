#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(ll a, ll b, ll p, ll q, ll x, ll dp[], ll n) {
    if (x == 0) return 0;
    if (x < 0 || x > n) return 1e10;
    if (dp[x] != -1) return dp[x];
    
    ll cost = max(f(a, b, p, q, x-a, dp, n), f(a, b, p, q, x-b, dp, n)) + max(p, q);
    return dp[x] = cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    
    rep(i, n) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    // dp[x] will store the minimum cost to achieve exactly x items
    ll dp[1000010] = {-1};
    dp[0] = 0; // Minimum cost to achieve 0 items is 0
    
    ll ans = 1e10;
    for (ll i = 0; i <= n; i++) {
        if (dp[i] != -1) {
            ans = min(ans, dp[i]);
        }
    }
    
    // Binary search for the maximum number of items that can be achieved
    ll left = 0, right = n;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll cost = 0;
        
        // Calculate the cost to achieve exactly mid items
        rep(i, n) {
            cost += min(dp[mid-a[i]], dp[mid-b[i]]) + max(p[i], q[i]);
        }
        
        if (cost <= x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << right;
    return 0;
}