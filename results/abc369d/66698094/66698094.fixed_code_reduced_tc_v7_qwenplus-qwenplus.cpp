#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    // dp[i][0] = max total when i-th element is taken with double value
    // dp[i][1] = max total when i-th element is taken normally
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    for (int i = 1; i <= n; ++i)
    {
        // Taking current element as double (can't take previous as double)
        dp[i][0] = dp[i - 1][1] + 2 * v[i - 1];
        // Taking current element normally (either from normal or double state)
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + v[i - 1];
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}