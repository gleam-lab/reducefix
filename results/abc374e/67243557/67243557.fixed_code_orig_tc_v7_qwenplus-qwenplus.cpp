#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// Computes minimal cost to buy exactly x candies of one type
ll f(ll a, ll b, ll p, ll q, ll x) {
    // dp[i] = min cost to buy i candies
    ll limit = max(a, b) * max(a, b); // cycle-based bound
    vector<ll> dp(limit + 2, 1e18);
    dp[0] = 0;

    // Build DP table
    for (ll i = 1; i <= limit; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }

    // Find the minimal cost for x candies using cycle decomposition
    ll base = a * b;
    ll full_cycles = x / base;
    ll remainder = x % base;

    return dp[base] * full_cycles + dp[remainder];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n), b(n), p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search on number of candies we can buy
    ll low = 0, high = 1e9;
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

    cout << answer << "\n";
    return 0;
}