#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
    ll dp[10010] = {1e10};
    dp[0] = 0;  // iåè²·ãæã®æå°å¤
    rep(i, 10000) {
        if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
        if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
    }
    reverse(dp, dp + 10010);  // reverse to start from high values of i

    ll ans = 0, tt = a * b;
    ll t = x / tt;
    ans += t * dp[tt];
    x %= tt;
    ans += dp[x];
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll now, l = 0, r = 1e10;
    while (l < r) {
        now = (l + r + 1) / 2;
        ll tmp = 0;
        rep(i, n) {
            tmp += f(a[i], b[i], p[i], q[i], now);
        }
        if (tmp <= x) l = now;
        else r = now - 1;
    }
    cout << l << endl;
    return 0;
}