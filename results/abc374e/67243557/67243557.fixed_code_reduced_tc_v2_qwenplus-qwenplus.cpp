#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(n);i++)
using ll = long long;

ll computeMinCost(ll a, ll b, ll p, ll q, ll target) {
    // Use dynamic programming to find minimum cost to buy `i` items
    vector<ll> dp(10010, 1e18);
    dp[0] = 0;

    for (ll i = 1; i < 10010; ++i) {
        if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
        if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
    }

    // Apply prefix min optimization
    for (ll i = 1; i < 10010; ++i) {
        dp[i] = min(dp[i], dp[i - 1]);
    }

    // Use periodicity optimization: a * b is a good bound
    ll period = a * b;
    ll full_cycles = target / period;
    ll remainder = target % period;

    return full_cycles * dp[period] + dp[remainder];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n), b(n), p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search on the number of snacks we can buy
    ll low = 0, high = 1e18;
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;

        for (int i = 0; i < n; ++i) {
            total_cost += computeMinCost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break;
        }

        if (total_cost <= x) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}