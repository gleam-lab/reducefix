#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// Function to compute the minimum cost to buy 'need' items using packages of a or b
ll f(ll a, ll b, ll p, ll q, ll need) {
    // We'll use dynamic programming up to a reasonable limit
    // Since a and b can be up to 3e5, we can't go beyond ~1e5 in DP

    // Optimization: Use cycle detection since costs repeat
    // The pattern repeats at most every lcm(a, b), but we cap it at 200,000
    const ll MAX = 200000;
    vector<ll> dp(MAX + 1, 1e18);
    dp[0] = 0;

    // Build the DP table
    for (ll i = 1; i <= MAX; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }

    // To avoid overflow and unnecessary computation,
    // we can optimize by finding how much it costs to buy "need" items
    // using prefix min to ensure we only take the best possible cost

    // Prefix min to optimize further
    for (ll i = 1; i <= MAX; ++i) {
        dp[i] = min(dp[i], dp[i - 1]);
    }

    // For large needs, use periodic properties
    // Find period and base cost per period
    ll period = 1;
    while (period <= MAX && dp[period] * 2 == dp[2 * period]) ++period;

    // Simple case: try to buy exactly 'need' items
    if (need <= MAX) return dp[need];

    // Otherwise, break into full periods and remainder
    ll full_cycles = need / period;
    ll remainder = need % period;

    return dp[period] * full_cycles + dp[remainder];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    // Binary search on the number of items that can be bought
    ll low = 0, high = 1e18;
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;

        // Calculate total cost for buying 'mid' items across all types
        for (int i = 0; i < n; ++i) {
            total_cost += f(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break; // Early exit if over budget
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