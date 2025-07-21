#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;

    // dp[i][0] = max total when i-th element is not flipped
    // dp[i][1] = max total when i-th element is flipped
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    // Base cases:
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }

    dp[1][0] = v[0];     // first element not flipped
    dp[1][1] = v[0] * 2; // first element flipped

    for (int i = 1; i < n; ++i)
    {
        dp[i + 1][0] = max(dp[i][1] + v[i], dp[i][0] + v[i]);
        dp[i + 1][1] = max(dp[i][0] + v[i] * 2, dp[i][1] + v[i]);
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}