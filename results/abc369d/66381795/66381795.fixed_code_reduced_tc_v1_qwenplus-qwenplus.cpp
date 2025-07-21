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

    // dp[i] = maximum sum we can get from first i elements
    vector<ll> dp(n + 1, 0);
    
    // Base case: dp[0] = 0 (no elements), dp[1] = data[0] (only one element)
    if (n >= 1) dp[1] = data[0];

    for (int i = 2; i <= n; ++i) {
        // Two options:
        // 1. Take previous element alone -> dp[i-1] + data[i-1]
        // 2. Take pair of previous two elements -> dp[i-2] + max(2*data[i-1], data[i-2]+data[i-1])
        ll option1 = dp[i-1] + data[i-1];
        ll option2 = dp[i-2] + max(2 * data[i-1], data[i-2] + data[i-1]);
        dp[i] = max(option1, option2);
    }

    cout << dp[n] << endl;
    return 0;
}