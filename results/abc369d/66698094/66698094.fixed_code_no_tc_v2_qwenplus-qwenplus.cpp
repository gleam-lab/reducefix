#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << '\n';
        return;
    }
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    // dp[i][0] = max total when up to i-th element, even index sum
    // dp[i][1] = max total when up to i-th element, odd index sum
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    // Base cases
    dp[1][0] = v[0]; // first element is at index 0 (even)
    dp[1][1] = 0;    // no second element yet

    for (int i = 2; i <= n; ++i)
    {
        // current element is at index i-1 (0-based)
        ll val = v[i - 1];

        // If current index (i-1) is even: we can add to previous odd sum
        if ((i - 1) % 2 == 0)
            dp[i][0] = dp[i - 1][1] + val;
        else
            dp[i][0] = dp[i - 1][0]; // not adding this value

        // If current index (i-1) is odd: we can add to previous even sum
        if ((i - 1) % 2 == 1)
            dp[i][1] = dp[i - 1][0] + val;
        else
            dp[i][1] = dp[i - 1][1]; // not adding this value
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}