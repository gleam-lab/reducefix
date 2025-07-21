#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// This function calculates the minimum cost to buy 'x' items using two types of bundles (a,p) and (b,q)
ll f(ll a, ll b, ll p, ll q, ll x) {
    // dp[i] = minimum cost to get exactly i items
    vector<ll> dp(x + 1, 1e18);
    dp[0] = 0;

    for (ll i = 0; i <= x; ++i) {
        if (i + a <= x) dp[i + a] = min(dp[i + a], dp[i] + p);
        if (i + b <= x) dp[i + b] = min(dp[i + b], dp[i] + q);
    }

    return dp[x];
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);

    rep(i, n) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search on the number of items we can buy with budget x
    ll low = 0, high = 1e18, ans = 0;

    while (low < high) {
        ll mid = (low + high + 1) / 2;
        ll total_cost = 0;

        rep(i, n) {
            total_cost += f(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break; // Avoid overflow
        }

        if (total_cost <= x) {
            ans = mid;
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}