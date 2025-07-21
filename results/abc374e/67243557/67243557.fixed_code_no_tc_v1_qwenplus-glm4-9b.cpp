#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

// Function to calculate the cost of producing x items with given cost of a and b
ll cost(int a, int b, int p, int q, int x) {
    vector<ll> dp(x + 1, 1e18);
    dp[0] = 0; // Cost of producing 0 items is 0

    // Fill dp array
    for (int i = 1; i <= x; i++) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }

    return dp[x]; // Minimum cost to produce x items
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search for the maximum number of items that can be produced
    ll low = 0, high = 1;
    while (high < x) high <<= 1;

    ll result = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;
        rep(i, n) {
            ll cost_per_item = cost(a[i], b[i], p[i], q[i], mid);
            total_cost += cost_per_item;
        }

        if (total_cost <= x) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}