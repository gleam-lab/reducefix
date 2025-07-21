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

    if (n == 0) {
        cout << 0 << '\n';
        return;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    // Base cases
    dp[1][0] = 0;          // not taking the first element
    dp[1][1] = v[0];      // taking the first element

    for (int i = 2; i <= n; ++i)
    {
        // Not taking the i-th element (1-based), so carry over max from previous step
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        // Taking the i-th element, must have not taken the previous one
        dp[i][1] = dp[i-1][0] + v[i-1];
    }

    // Max of taking or not taking last element
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