#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        // Pair A and B and sort by A descending to maximize the max of A_i
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {A[i], B[i]};
        }
        sort(p.begin(), p.end(), greater<pair<int, int>>());

        // Use a prefix sum array for B to calculate the sum for any subset
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + p[i - 1].second;
        }

        // We need to find the minimum value of (max of K elements in A) * (sum of subset in B)
        long long minValue = LLONG_MAX;
        for (int i = k; i <= n; i++) {
            // Choose the i-th largest element from A as the maximum of the subset
            int maxA = p[i - 1].first;
            // Calculate the sum of the subset in B
            int sumB = prefixSum[i - 1];
            // Update the minimum value
            minValue = min(minValue, maxA * sumB);
        }

        // Output the result for the current test case
        cout << minValue << '\n';
    }

    return 0;
}