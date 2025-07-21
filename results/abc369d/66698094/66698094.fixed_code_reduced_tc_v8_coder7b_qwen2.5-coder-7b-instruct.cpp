#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// freopen("equal.in", "r", stdin); freopen("output.txt", "w", stdout);
const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    ll dp[n + 1][2];
    for (ll &x : v)
        cin >> x;
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = dp[i][1] = -1;
    }
    dp[0][0] = dp[0][1] = 0;
    dp[1][1] = dp[1][0] = v[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i + 1][0] = max((dp[i + 1][0] % MOD + dp[i][1] % MOD + 2 * v[i] % MOD) % MOD, (dp[i][0] % MOD + v[i] % MOD) % MOD);
        dp[i + 1][1] = max((dp[i + 1][1] % MOD + dp[i][0] % MOD + v[i] % MOD) % MOD, (dp[i][1] % MOD + 2 * v[i] % MOD) % MOD);
    }
    cout << max((dp[n][0] % MOD + dp[n][1] % MOD) % MOD) << '\n';
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