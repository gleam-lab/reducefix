#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// Function to compute the minimum cost to buy 'need' items using two types of packs
ll f(ll a, ll b, ll p, ll q, ll need) {
    // We want to buy at least 'need' items using combinations of a and b with minimal cost
    
    // Since a and b can be large, we use dynamic programming up to a reasonable limit
    // The maximum number of items we might consider in one pack is LCM(a,b) or around 1e4
    const ll MAX_ITEMS = 20000; // Increased buffer size
    vector<ll> dp(MAX_ITEMS + 1, 1e18);
    dp[0] = 0;

    // Build DP table: dp[i] = min cost to get at least i items
    for (ll i = 0; i <= MAX_ITEMS; ++i) {
        if (i + a <= MAX_ITEMS)
            dp[i + a] = min(dp[i + a], dp[i] + p);
        if (i + b <= MAX_ITEMS)
            dp[i + b] = min(dp[i + b], dp[i] + q);
    }

    // For each possible count up to MAX_ITEMS, ensure we have the best minimum cost
    for (ll i = 1; i <= MAX_ITEMS; ++i)
        dp[i] = min(dp[i], dp[i - 1]);

    // If needed items are within our precomputed range
    if (need <= MAX_ITEMS)
        return dp[need];

    // Else, use periodic property of item counts
    ll period = a * b / gcd(a, b); // Least common multiple
    ll full_cycles = need / period;
    ll remainder = need % period;

    // Cost for full cycles plus remaining items
    return full_cycles * dp[period] + dp[remainder];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    // Binary search on the number of items that can be bought
    ll low = 0, high = 1e14, ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;

        // Calculate total cost to buy 'mid' items from all stores
        for (int i = 0; i < n; ++i)
            total_cost += f(a[i], b[i], p[i], q[i], mid);

        if (total_cost <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}