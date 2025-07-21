#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    // dp[i][0]: maximum value we can get if we don't take the i-th element
    // dp[i][1]: maximum value we can get if we take the i-th element
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = dp[1][1] = v[0];
    
    for (int i = 1; i < n; ++i) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 2 * v[i]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + v[i]);
    }
    
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}