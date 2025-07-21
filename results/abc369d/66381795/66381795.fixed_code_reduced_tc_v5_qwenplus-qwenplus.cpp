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
    
    // Base cases
    if (n >= 1) dp[1] = data[0]; // Only one element - take it as single
    if (n >= 2) dp[2] = max(data[0] + data[1], 2 * max(data[0], data[1])); // Two elements
    
    // For each position i >= 3
    for (int i = 3; i <= n; i++) {
        // Option 1: Take current element alone
        ll option1 = dp[i - 1] + data[i - 1];
        
        // Option 2: Take current and previous as pair (only if i >= 2)
        ll option2 = dp[i - 2] + 2 * max(data[i - 1], data[i - 2]);
        
        dp[i] = max(option1, option2);
    }
    
    cout << dp[n] << endl;
    return 0;
}