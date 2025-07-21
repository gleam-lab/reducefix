#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(ll a, ll b, ll p, ll q, ll x) {
    ll ans = 1e10;
    vector<ll> dp(10001, 1e10);
    dp[0] = 0;
    for (ll i = 1; i <= 10000; i++) {
        if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
        if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
        dp[i] = min(dp[i], ans); // Ensure dp[i] holds the minimum cost for any i
    }
    dp[10001] = ans; // Sentinel value to handle case when x is exactly at the boundary

    for (ll i = 10001; i >= 0; i--) {
        if (dp[i] <= x) {
            ans = dp[i];
            x -= dp[i];
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), p(n), q(n);
    rep(i, n) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll now; // wã®åè£
    ll l = 0, r = 1e10;
    while (r - l > 1) {
        now = (r + l) / 2;
        ll tmp = 0;
        rep(i, n) {
            tmp += f(a[i], b[i], p[i], q[i], now);
        }
        if (tmp <= x) l = now;
        else r = now;
    }
    cout << l;
    return 0;
}