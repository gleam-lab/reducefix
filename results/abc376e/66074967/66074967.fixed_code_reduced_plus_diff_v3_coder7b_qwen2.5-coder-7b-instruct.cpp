#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        // Sort pairs based on A[i]
        vector<pii> ab(n);
        for (int i = 0; i < n; ++i) {
            ab[i] = {A[i], B[i]};
        }
        sort(ab.begin(), ab.end());

        // Calculate prefix sums for B
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + ab[i].second;
        }

        long long minProduct = LLONG_MAX;
        for (int i = k - 1; i < n; ++i) {
            long long currentMax = ab[i].first;
            long long currentSum = prefixSum[i + 1] - prefixSum[i - k + 1];
            minProduct = min(minProduct, currentMax * currentSum);
        }

        cout << minProduct << '\n';
    }

    return 0;
}