#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort the indices based on A values
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return a[i] > a[j];
        });

        // Calculate prefix sums of B
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + b[indices[i]];
        }

        // Find the minimum possible value
        int minVal = LLONG_MAX;
        for (int i = 0; i <= n - k; ++i) {
            int maxA = a[indices[i]];
            int sumB = prefixSum[i + k] - prefixSum[i];
            minVal = min(minVal, maxA * sumB);
        }

        cout << minVal << '\n';
    }

    return 0;
}