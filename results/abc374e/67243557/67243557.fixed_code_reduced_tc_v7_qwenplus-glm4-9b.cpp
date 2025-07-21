#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) begin(x), end(x)

using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
    ll z = x;
    ll ans = 0;
    vector<ll> dp(x + 1, 1e18);
    dp[0] = 0;
    for (ll i = 1; i <= x; i++) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    ll tt = a * b;
    for (ll i = x; i >= 0; i--) {
        if (i >= tt) dp[i] = min(dp[i], dp[i - tt] + p + q);
    }
    for (ll i = 0; i <= x; i++) {
        if (i >= tt) {
            ans = min(ans, dp[i]);
        }
    }
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<ll, pair<ll, ll>>> v(n);
    rep(i, n) {
        ll a, p, b, q;
        cin >> a >> p >> b >> q;
        v[i] = {a, {p, b}};
    }
    sort(all(v));
    ll now; // wã®åè£
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        now = (r + l) / 2;
        ll tmp = 0;
        rep(i, n) {
            ll a, b, p, q;
            tie(a, tie(p, b)) = v[i];
            tmp += f(a, b, p, q, now);
        }
        if (tmp <= x) l = now;
        else r = now;
    }
    cout << l;
    return 0;
}