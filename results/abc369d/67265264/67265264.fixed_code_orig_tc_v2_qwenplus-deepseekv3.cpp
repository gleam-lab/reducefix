#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for (int i = 1; i <= n; ++i) {
        // If we do not take the current element, carry forward the previous state
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        // If we take the current element with parity 0 (no multiplication)
        dp[i][1] = dp[i-1][0] + v[i-1];
        // But we can also consider taking it with parity 1 (multiplication)
        if (i > 1) {
            dp[i][0] = max(dp[i][0], dp[i-1][1] + 2 * v[i-1]);
        }
    }
    
    cout << max(dp[n][0], dp[n][1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    return 0;
}