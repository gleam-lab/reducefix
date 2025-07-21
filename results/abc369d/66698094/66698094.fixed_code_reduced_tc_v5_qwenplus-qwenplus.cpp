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

    // dp[i][0] = max sum when considering first i elements and last element is not flipped
    // dp[i][1] = max sum when considering first i elements and last element is flipped (multiplied by 2)
    ll dp[n + 1][2];

    dp[0][0] = dp[0][1] = 0;
    
    if (n >= 1) {
        dp[1][0] = v[0];  // not flipped
        dp[1][1] = v[0];  // flipped (but only one element, so same value)
    }

    for (int i = 1; i < n; ++i)
    {
        // Transition: if current element is not flipped, previous must be flipped
        dp[i + 1][0] = dp[i][1] + v[i];
        // If current element is flipped (multiplied by 2), previous can be either flipped or not
        dp[i + 1][1] = max(dp[i][0] + 2 * v[i], dp[i][1] + v[i]);
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