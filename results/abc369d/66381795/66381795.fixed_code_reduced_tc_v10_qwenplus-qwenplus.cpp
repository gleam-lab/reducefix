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
    
    // Base case: no elements selected
    dp[0] = 0;
    
    // For one element, we can only take it once
    if (n >= 1)
        dp[1] = data[0];
    
    // For two elements, we can either:
    // - take both and double the sum: 2*(a+b)
    // - or just take one of them
    if (n >= 2)
        dp[2] = max(2 * (data[0] + data[1]), max(data[0], data[1]));

    // Fill dp array
    for (int i = 3; i <= n; i++) {
        // Option 1: don't include current element
        ll option1 = dp[i - 1];
        
        // Option 2: include current element alone
        ll option2 = dp[i - 1] + data[i - 1];
        
        // Option 3: include previous and current as pair and double their sum
        ll option3 = dp[i - 2] + 2 * (data[i - 1] + data[i - 2]);
        
        dp[i] = max({option1, option2, option3});
    }

    cout << dp[n] << endl;
    return 0;
}