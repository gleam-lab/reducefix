#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve one test case
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    // Sort A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Compute prefix sums for B
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + B[i - 1];
    }

    long long minExpression = LLONG_MAX;
    // Use two pointers to find the optimal subset
    int start = 0;
    for (int end = n - k; end < n; ++end) {
        long long sum = prefixSum[n] - prefixSum[end + 1];
        minExpression = min(minExpression, A[end + k - 1] * sum);
    }

    // Output the result for the current test case
    cout << minExpression << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}