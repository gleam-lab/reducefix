#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1e18

using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
    ll dp[x + 1];
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;

    for (ll j = 0; j <= x; j++) {
        if (j >= a) {
            dp[j] = min(dp[j], dp[j - a] + p);
        }
        if (j >= b) {
            dp[j] = min(dp[j], dp[j - b] + q);
        }
    }

    return dp[x];
}

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    rep(i, n) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll l = 0, r = 1000000000;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            cost += f(a[i], b[i], p[i], q[i], mid);
        }
        if (cost <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
    return 0;
}