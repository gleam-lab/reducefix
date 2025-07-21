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
    // Handle base cases
    if (n >= 1) dp[1] = data[0]; // Only one element: take it normally

    for (int i = 2; i <= n; ++i) {
        // Option 1: Take current element normally
        dp[i] = dp[i - 1] + data[i - 1];

        // Option 2: Pair previous and current element
        if (i >= 2) {
            dp[i] = max(dp[i], dp[i - 2] + 2 * data[i - 1]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}