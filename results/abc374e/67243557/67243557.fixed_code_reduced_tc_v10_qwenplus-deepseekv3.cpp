#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
using ll = long long;

ll compute_cost(ll a, ll b, ll p, ll q, ll items) {
    vector<ll> dp(items + 1, LLONG_MAX / 2);
    dp[0] = 0;
    for (ll i = 1; i <= items; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    return dp[items];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll left = 0, right = 1e18;
    ll answer = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total_cost = 0;
        bool feasible = true;
        rep(i, n) {
            ll cost = compute_cost(a[i], b[i], p[i], q[i], mid);
            if (cost > x) {
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
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}