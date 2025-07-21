#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll required) {
    // We want to buy at least 'required' number of items, minimizing the cost
    
    // dp[i] = minimum cost to get exactly i items
    // Since a and b can be up to 1e3, we limit our DP to a reasonable range
    const ll MAX = 2000; // slightly more than max(a,b)
    vector<ll> dp(MAX + 5, 1e18);
    dp[0] = 0;

    // Unbounded knapsack to fill dp
    for (ll i = 0; i <= MAX; ++i) {
        if (dp[i] != 1e18) {
            if (i + a <= MAX) dp[i + a] = min(dp[i + a], dp[i] + p);
            if (i + b <= MAX) dp[i + b] = min(dp[i + b], dp[i] + q);
        }
    }

    // Find the minimal cost to buy at least "required" items
    ll min_cost = 1e18;
    for (ll i = required; i <= MAX; ++i) {
        min_cost = min(min_cost, dp[i]);
    }

    return min_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search on the number of weeks
    ll low = 0;
    ll high = 1e14; // upper bound on possible weeks
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;

        for (int i = 0; i < n; ++i) {
            total_cost += compute_min_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break; // early exit if budget is exceeded
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