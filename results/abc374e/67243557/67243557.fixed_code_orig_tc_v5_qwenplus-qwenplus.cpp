#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
    // DP[i] = minimum cost to buy i items
    ll max_items = min(2 * max(a, b), (ll)1e5);  // Safe upper bound for precomputation

    vector<ll> dp(max_items + 1, 1e18);
    dp[0] = 0;

    for (int i = 1; i <= max_items; ++i) {
        if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
        if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
    }

    // Use the periodic nature of the problem
    ll cycle_cost = dp[a * b];
    ll full_cycles = x / (a * b);
    ll remaining = x % (a * b);

    return full_cycles * cycle_cost + dp[remaining];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    vector<int> a(n), b(n), p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search on the number of boxes we can buy
    ll low = 0, high = 1e18;
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;

        for (int i = 0; i < n; ++i) {
            total_cost += f(a[i], b[i], p[i], q[i], mid);
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