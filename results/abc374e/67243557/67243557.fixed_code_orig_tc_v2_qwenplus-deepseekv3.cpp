#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll x) {
    ll max_items = x;
    vector<ll> dp(max_items + 1, LLONG_MAX);
    dp[0] = 0;
    for (ll i = 1; i <= max_items; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    return dp[max_items];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll l = 0, r = 1e18;
    ll answer = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll total_cost = 0;
        bool feasible = true;
        rep(i, n) {
            ll cost = compute_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost == LLONG_MAX) {
                feasible = false;
                break;
            }
            total_cost += cost;
            if (total_cost > x) {
                feasible = false;
                break;
            }
        }
        if (feasible) {
            answer = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}