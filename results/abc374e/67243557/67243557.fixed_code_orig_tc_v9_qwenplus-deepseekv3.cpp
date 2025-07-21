#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll x) {
    ll gcd_ab = gcd(a, b);
    ll lcm_ab = (a / gcd_ab) * b;
    ll max_dp = lcm_ab * 2;
    vector<ll> dp(max_dp + 1, LLONG_MAX);
    dp[0] = 0;
    for (ll i = 1; i <= max_dp; ++i) {
        if (i >= a && dp[i - a] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - a] + p);
        }
        if (i >= b && dp[i - b] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[i - b] + q);
        }
    }
    for (ll i = max_dp - 1; i >= 0; --i) {
        dp[i] = min(dp[i], dp[i + 1]);
    }
    ll full_cycles = x / lcm_ab;
    ll remaining = x % lcm_ab;
    ll cost = full_cycles * dp[lcm_ab];
    if (remaining > 0) {
        cost += dp[remaining];
    }
    return cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll low = 0, high = 1e18;
    ll answer = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_cost = 0;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            ll cost = compute_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost > x) {
                possible = false;
                break;
            }
            total_cost += cost;
            if (total_cost > x) {
                possible = false;
                break;
            }
        }
        if (possible) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}