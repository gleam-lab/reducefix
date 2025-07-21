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

    // dp[i][0] = max total when the i-th element is not flipped
    // dp[i][1] = max total when the i-th element is flipped
    ll dp_prev[2] = {0, 0}; // previous state (i-1)
    ll dp_curr[2];          // current state (i)

    for (int i = 0; i < n; ++i)
    {
        // Transition from i to i+1
        dp_curr[0] = dp_prev[1] + (i == 0 ? v[0] : 2 * v[i]);
        dp_curr[1] = dp_prev[0] + v[i];

        dp_prev[0] = dp_curr[0];
        dp_prev[1] = dp_curr[1];
    }

    cout << max(dp_prev[0], dp_prev[1]) << '\n';
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