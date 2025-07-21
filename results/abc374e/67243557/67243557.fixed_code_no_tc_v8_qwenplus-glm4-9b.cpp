#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(ll a, ll b, ll p, ll q, ll x) {
    vector<ll> dp(10010, 1e18);
    dp[0] = 0; // iåè²·ãæã®æå°å¤
    for (ll i = 1; i <= 10000; i++) {
        if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
        if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n), b(n); // a and b are pairs of cost and profit
    vector<ll> p(n), q(n);
    rep(i, n) {
        cin >> a[i].first >> p[i] >> a[i].second >> q[i];
        b[i] = a[i];
    }
    // Sort by cost descending for binary search
    sort(b.rbegin(), b.rend());
    
    ll now; // wã®åè£
    ll l = 0, r = 10000000000;
    while (r - l > 1) {
        now = (r + l) / 2;
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += f(b[i].first, b[i].second, p[i], q[i], now);
        }
        if (tmp <= x) l = now;
        else r = now;
    }
    cout << l;
    return 0;
}