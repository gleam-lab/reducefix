#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        // Use a max-heap to store indices of A for the largest K elements
        priority_queue<int> maxHeap;
        int sumB = 0;
        
        // Calculate prefix sum of B
        vector<int> prefixSumB(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            prefixSumB[i + 1] = prefixSumB[i] + B[i];
        }

        // Calculate the minimum value
        long long ans = LLONG_MAX;
        for (int i = K - 1; i < N; ++i) {
            maxHeap.push(A[i]);
            sumB = prefixSumB[i + 1];

            // Check if the last K elements are the best choice
            ans = min(ans, sumB * A[i] - sumB * maxHeap.top());
        }

        cout << ans << '\n';
    }
    return 0;
}