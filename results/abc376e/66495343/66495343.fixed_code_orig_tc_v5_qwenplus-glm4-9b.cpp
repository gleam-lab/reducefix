#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

        vector<long long> prefixSum(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            prefixSum[i] = prefixSum[i - 1] + B[i - 1];
        }

        long long minResult = LLONG_MAX;
        stack<pair<int, long long>> maxHeap; // stores (index, sum)
        long long sum = 0;

        for (int i = 0; i < N; ++i) {
            // Maintain only k largest sums in the heap
            while (!maxHeap.empty() && maxHeap.top().second <= prefixSum[i] - prefixSum[i - K + 1]) {
                sum -= maxHeap.top().second;
                maxHeap.pop();
            }

            // Calculate the current result
            long long currentResult = A[i] * sum;
            minResult = min(minResult, currentResult);

            // Update the heap with the current sum
            maxHeap.push({i, prefixSum[i] - prefixSum[i - K + 1]});
            sum += prefixSum[i] - prefixSum[i - K + 1];
        }

        cout << minResult << endl;
    }
    return 0;
}