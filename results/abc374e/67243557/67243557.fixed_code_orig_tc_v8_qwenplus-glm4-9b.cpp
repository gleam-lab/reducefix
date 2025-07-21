#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

ll min_cost(int idx, const vector<int>& a, const vector<int>& b, const vector<int>& p, const vector<int>& q, ll x) {
    vector<ll> dp(10010, 1e10);
    dp[0] = 0;
    for (int i = 1; i < 10010; i++) {
        if (i >= a[idx]) dp[i] = min(dp[i], dp[i - a[idx]] + p[idx]);
        if (i >= b[idx]) dp[i] = min(dp[i], dp[i - b[idx]] + q[idx]);
    }
    for (int i = 0; i < 10010; i++) dp[10009 - i] = min(dp[10009 - i], dp[10010 - i - 1]);
    return dp[x];
}

ll f(ll a, ll b, ll p, ll q, ll x) {
    ll z = x;
    ll ans = 0;
    vector<ll> dp(10010, 1e10);
    dp[0] = 0;
    for (int i = 1; i < 10010; i++) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    for (int i = 0; i < 10010; i++) dp[10009 - i] = min(dp[10009 - i], dp[10010 - i - 1]);
    ll tt = a * b;
    ll t = x / tt;
    ans += dp[tt] * t;
    x %= tt;
    ans += dp[x];
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll now; // wã®åè£
    ll l = 0, r = 10000000000;
    while (r - l > 1) {
        now = (r + l) / 2;
        ll tmp = 0;
        rep(i, n) tmp += min_cost(i, a, b, p, q, now);
        if (tmp <= x) l = now;
        else r = now;
    }
    cout << (r + l) / 2;
    return 0;
}