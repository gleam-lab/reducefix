#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    // dp[i][0] = max score considering first i elements, last element not flipped
    // dp[i][1] = max score considering first i elements, last element flipped

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    
    // Base cases:
    dp[0][0] = 0; dp[0][1] = 0;  // No elements taken
    if (n >= 1) {
        dp[1][0] = v[0];  // First element not flipped
        dp[1][1] = v[0];  // Flipping one element doesn't change it
    }

    for (int i = 1; i < n; ++i)
    {
        // If we don't flip the current element (v[i]):
        // - Previous must be flipped to avoid equal consecutive in original array
        dp[i+1][0] = dp[i][1] + v[i];

        // If we flip the current element:
        // - It becomes 2 * v[i], and previous must not be flipped
        //   to avoid equal consecutive in flipped array
        dp[i+1][1] = dp[i][0] + 2 * v[i];
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}