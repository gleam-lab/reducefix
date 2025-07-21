#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    // dp[i] = max total sum considering first i elements
    vector<ll> dp(n + 1, 0);
    // Base case: dp[0] = 0 (no elements)
    
    // For 1-based index
    for (int i = 1; i <= n; ++i) {
        // Option 1: take current element alone
        dp[i] = dp[i - 1] + data[i - 1];
        
        // Option 2: if i >= 2, pair data[i-2] and data[i-1]
        if (i >= 2) {
            ll pair_value = 2 * max(data[i - 2], data[i - 1]);
            dp[i] = max(dp[i], dp[i - 2] + pair_value);
        }
    }

    cout << dp[n] << endl;
    return 0;
}