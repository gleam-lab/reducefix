#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long dp[n][2];
    dp[0][0] = nums[0];
    dp[0][1] = nums[0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + nums[i];
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << '\n';

    return 0;
}