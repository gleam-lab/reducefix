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

    dp[1][0] = v[0]; // take first as odd
    dp[1][1] = v[0]; // take first as even

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i-1][1] + v[i-1], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0] + v[i-1], dp[i-1][1]);
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