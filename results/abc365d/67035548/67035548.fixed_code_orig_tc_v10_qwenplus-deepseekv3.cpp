#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // DP table: dp[i][0] = R, dp[i][1] = P, dp[i][2] = S
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Initialize the first step
    dp[0][0] = (s[0] == 'S') ? 1 : 0; // R beats S
    dp[0][1] = (s[0] == 'R') ? 1 : 0; // P beats R
    dp[0][2] = (s[0] == 'P') ? 1 : 0; // S beats P

    for (int i = 1; i < n; ++i) {
        // R choice
        int max_prev = max(dp[i-1][1], dp[i-1][2]);
        dp[i][0] = max_prev + (s[i] == 'S' ? 1 : 0);

        // P choice
        max_prev = max(dp[i-1][0], dp[i-1][2]);
        dp[i][1] = max_prev + (s[i] == 'R' ? 1 : 0);

        // S choice
        max_prev = max(dp[i-1][0], dp[i-1][1]);
        dp[i][2] = max_prev + (s[i] == 'P' ? 1 : 0);
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}