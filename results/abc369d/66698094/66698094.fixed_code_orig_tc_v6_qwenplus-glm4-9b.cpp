#include <iostream>
#include <vector>
#include <limits>
#include <climits>

using namespace std;

const int N = 2e5 + 5;
ll min_diff = LLONG_MAX;
ll min_largest, min_smallest;

void find_min_diff(const vector<ll>& a, vector<vector<ll>>& dp) {
    for (int i = 1; i < a.size(); ++i) {
        dp[i][0] = min(dp[i - 1][0] + a[i], a[i]);
        dp[i][1] = max(dp[i - 1][1] + a[i], a[i]);
        if (abs(dp[i][0] - dp[i][1]) < min_diff) {
            min_diff = abs(dp[i][0] - dp[i][1]);
            min_largest = dp[i][1];
            min_smallest = dp[i][0];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[1][0] = min(0LL, a[0]);
    dp[1][1] = max(0LL, a[0]);

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][0] + a[i - 1], a[i - 1]);
        dp[i][1] = max(dp[i - 1][1] + a[i - 1], a[i - 1]);
    }

    for (auto& row : dp) {
        find_min_diff(a, row);
    }

    cout << min_diff << endl;
    return 0;
}