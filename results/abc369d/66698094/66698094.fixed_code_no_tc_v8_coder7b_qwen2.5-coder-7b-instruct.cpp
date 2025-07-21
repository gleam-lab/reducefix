#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;

    // Initialize DP array with appropriate size and values
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
    dp[0][0] = dp[0][1] = 0;
    
    // Fill DP table
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 2LL * v[i]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + v[i]);
    }

    // Output the maximum value between two states
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    fast;
    int t = 1;
    // Uncomment to use multiple test cases
    // cin >> t;
    while (t--) solve();
    return 0;
}