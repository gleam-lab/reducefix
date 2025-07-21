#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> dp(2);
    dp[0] = 0;
    dp[1] = -1e18;
    for (int i = 0; i < N; i++) {
        vector<long long> new_dp(2);
        new_dp[0] = max(dp[0], dp[1]);
        new_dp[1] = max(dp[0] + A[i], (i > 0) ? dp[1] + 2 * A[i] : -1e18);
        dp = new_dp;
    }
    long long ans = max(dp[0], dp[1]);
    cout << ans << endl;
    return 0;
}