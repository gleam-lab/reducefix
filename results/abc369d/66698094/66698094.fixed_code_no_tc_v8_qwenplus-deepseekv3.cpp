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
    for (ll &x : v) cin >> x;

    // dp[i][0] : not doubled at i-th step
    // dp[i][1] : doubled at i-th step
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    
    dp[0][0] = 0;
    dp[0][1] = -1e18; // Initially, we cannot double before the first element

    for (int i = 1; i <= n; ++i) {
        // If we do not double the current element
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + v[i - 1];
        // If we double the current element, we must have not doubled the previous
        dp[i][1] = dp[i - 1][0] + 2 * v[i - 1];
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    fast;
    int t = 1;
    while (t--) solve();
    return 0;
}