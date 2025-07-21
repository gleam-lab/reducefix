for (int i = 1; i <= n; ++i) {
    dp[i][0] = max(dp[i][0], dp[i - 1][1] + v[i - 1]);
    dp[i][1] = max(dp[i][1], dp[i - 1][0] + v[i - 1]);
}