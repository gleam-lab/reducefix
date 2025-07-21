#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
    ll z = x;
    ll ans = 0;
    vector<ll> dp(1000010, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= 1000010; i++) {
        if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
        if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
    }

    ll tt = a * b;
    ll t = (ll)(x / tt);
    ans += dp[tt] * t;
    x %= tt;
    ans += dp[x];
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll now;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        now = (r + l) / 2;
        ll tmp = 0;
        rep(i, n) tmp += f(a[i], b[i], p[i], q[i], now);
        if (tmp <= x) l = now;
        else r = now;
    }
    cout << l - 1;
    return 0;
}