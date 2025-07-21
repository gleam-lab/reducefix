#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        // Sort A in descending order
        sort(A.begin(), A.end(), greater<int>());

        // Priority queue to store the sums of the smallest K elements in B
        priority_queue<int, vector<int>, greater<int>> pq;

        // Calculate prefix sums of B
        vector<long long> prefixSum(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            prefixSum[i] = prefixSum[i - 1] + B[i - 1];
        }

        // Initialize the answer with a large value
        long long ans = LLONG_MAX;

        // Try to form all subsets of size K
        for (int i = 0; i <= N - K; i++) {
            long long sumB = 0;
            // Add the largest K elements of B to sumB
            for (int j = 0; j < K; j++) {
                sumB += B[i + j];
            }
            // Calculate the product with the maximum element from A
            long long product = sumB * A[i + K - 1];
            // Update the answer if this product is smaller
            ans = min(ans, product);
        }

        cout << ans << '\n';
    }
    return 0;
}