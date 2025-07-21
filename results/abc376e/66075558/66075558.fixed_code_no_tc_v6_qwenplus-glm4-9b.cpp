#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort by A values
        sort(a.begin(), a.end());

        // Calculate prefix sums of B values
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + b[a[i].second];
        }

        // Initialize minimum result as a large value
        long long minResult = LLONG_MAX;

        // Iterate over all possible k-length prefixes of B
        for (int i = k; i <= n; ++i) {
            // Calculate the maximum A value in the current prefix of A
            long long maxA = a[i - 1].first;
            // Calculate the sum of B values in the current prefix of B
            long long sumB = prefixSum[i] - prefixSum[i - k];
            // Calculate the result and update the minimum result
            minResult = min(minResult, maxA * sumB);
        }

        // Output the minimum result for this test case
        cout << minResult << endl;
    }
    return 0;
}