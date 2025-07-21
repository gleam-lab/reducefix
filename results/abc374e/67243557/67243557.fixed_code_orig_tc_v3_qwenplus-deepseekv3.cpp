#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll widgets) {
    vector<ll> dp(widgets + 1, LLONG_MAX);
    dp[0] = 0;
    for (ll i = 1; i <= widgets; ++i) {
        if (i >= a) {
            if (dp[i - a] != LLONG_MAX) {
                dp[i] = min(dp[i], dp[i - a] + p);
            }
        }
        if (i >= b) {
            if (dp[i - b] != LLONG_MAX) {
                dp[i] = min(dp[i], dp[i - b] + q);
            }
        }
    }
    return dp[widgets];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll left = 0;
    ll right = 1e12; // Upper bound for binary search
    ll answer = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total_cost = 0;
        bool feasible = true;

        for (int i = 0; i < n; ++i) {
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
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}