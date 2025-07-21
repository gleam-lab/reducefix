#include <bits/stdc++.h>
using namespace std;

#define INF (long long)(1e18)

int main() {
    int n;
    long long dp[2] = {0, -INF};
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long temp = dp[0];
        dp[0] = max(dp[1] + (2 * x), dp[0]);
        dp[1] = max(temp + x, dp[1]);
    }

    cout << max(dp[0], dp[1]) << endl;
    return 0;
}