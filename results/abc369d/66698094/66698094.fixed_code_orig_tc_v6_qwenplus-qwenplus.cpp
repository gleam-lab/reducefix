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
    ll dp[n + 1][2];
    
    for (ll &x : v)
        cin >> x;
    
    // Initialize dp table with 0s
    memset(dp, 0, sizeof(dp));
    
    // Base case: zero elements selected
    dp[0][0] = 0; // not taking last
    dp[0][1] = 0; // took last

    for (int i = 1; i <= n; ++i)
    {
        // Case 0: current element is NOT taken
        // We can either have taken or not taken the previous one
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);

        // Case 1: current element IS taken
        // Previous must not be taken
        dp[i][1] = dp[i-1][0] + v[i-1];
    }

    // The answer is the maximum of the two ways to end the sequence
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