#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// Function to compute minimum cost to buy 'need' items of types a and b with prices p and q
ll f(ll a, ll b, ll p, ll q, ll need) {
    // We will use DP to find the minimum cost to buy exactly 'need' items using packages of size a and b
    vector<ll> dp(need + 10, 1e18);
    dp[0] = 0;

    for (ll i = 0; i <= need; ++i) {
        if (i + a <= need) dp[i + a] = min(dp[i + a], dp[i] + p);
        if (i + b <= need) dp[i + b] = min(dp[i + b], dp[i] + q);
    }

    // Return the minimum cost to get at least 'need' items
    return *min_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n), b(n), p(n), q(n);

    rep(i, n) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search on maximum number of items we can buy
    ll left = 0, right = 2e5; // Since max item count is limited by budget and package sizes
    ll answer = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total_cost = 0;

        rep(i, n) {
            total_cost += f(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break;
        }

        if (total_cost <= x) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}