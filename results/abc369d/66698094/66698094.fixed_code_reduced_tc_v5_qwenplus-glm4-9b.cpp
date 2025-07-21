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
    ll dp[n + 1];
    for (ll &x : v)
        cin >> x;
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = v[0];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i - 1]);
    }
    cout << dp[n] << '\n';
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