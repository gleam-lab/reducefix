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
    ll dp[2];
    for (ll &x : v)
        cin >> x;
    dp[0] = dp[1] = 0;
    dp[1] = v[0];
    for (int i = 1; i < n; ++i)
    {
        ll new_dp[2];
        new_dp[0] = max(dp[1] + 2 * v[i], dp[0] + v[i]);
        new_dp[1] = max(dp[0], dp[1] + v[i]);
        dp[0] = new_dp[0];
        dp[1] = new_dp[1];
    }
    cout << max(dp[0], dp[1]) << '\n';
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