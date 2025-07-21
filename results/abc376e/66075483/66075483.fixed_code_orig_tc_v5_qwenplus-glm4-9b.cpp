#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort A in descending order
        sort(A.begin(), A.end(), greater<int>());

        // Calculate prefix sums for B
        vector<int> prefix_sum(N, 0);
        partial_sum(B.begin(), B.end(), prefix_sum.begin());

        // Use dynamic programming to find the minimum possible value
        vector<long long> dp(N + 1, LLONG_MAX);
        dp[0] = 0; // Base case: no elements in the subset

        for (int i = 0; i < N; ++i) {
            if (i >= K) {
                dp[i + 1] = min(dp[i + 1], dp[i - K] + prefix_sum[i]);
            }
            dp[i + 1] = min(dp[i + 1], dp[i] + prefix_sum[i] - (i >= K ? prefix_sum[i - K] : 0));
        }

        // The minimum value of the expression
        cout << A[0] * dp[N] << endl;
    }

    return 0;
}