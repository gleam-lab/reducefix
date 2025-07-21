#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    unsigned long long dp0 = 0, dp1 = 0, x;

    cin >> n;

    vector<unsigned long long> dp(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        dp[i + 1] = max(dp[i], dp[i + 1]);
        dp[i + 1] = max(dp[i + 1], dp[i] + x);
        dp[i + 1] = max(dp[i + 1], dp[i] + 2 * x);
    }

    cout << dp[n] << endl;

    return 0;
}