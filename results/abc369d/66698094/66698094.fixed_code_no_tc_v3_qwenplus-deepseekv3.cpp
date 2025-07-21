#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// freopen("equal.in", "r", stdin); freopen("output.txt", "w", stdout);
const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v)
        cin >> x;
    
    ll dp[n + 1][2];
    // Initialize DP table to negative infinity to represent unreachable states
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = dp[i][1] = -1e18;
    }
    // Base case: no elements selected
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for (int i = 0; i < n; ++i) {
        // Transition from state 0 to state 1 by selecting current element
        if (dp[i][0] != -1e18) {
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + v[i]);
        }
        // Transition from state 1 to state 0 by selecting current element multiplied by 2
        if (dp[i][1] != -1e18) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 2 * v[i]);
        }
        // Also, carry forward the previous state without selecting current element
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}