#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];

        // Sort the pairs of (A[i], B[i]) by A[i] in descending order
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) pairs[i] = {A[i], B[i]};
        sort(pairs.rbegin(), pairs.rend());

        // We need to find the minimum value of (max Ai in S) * (sum Bi in S)
        // where S is a subset of size K
        long long sum = 0, maxA = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Initialize the min heap with the first K-1 B[i] values
        for (int i = 0; i < k - 1; i++) {
            minHeap.push(pairs[i].second);
            sum += pairs[i].second;
        }

        // Iterate over the remaining elements to find the optimal subset of size K
        for (int i = k - 1; i < n; i++) {
            sum += pairs[i].second;
            maxA = pairs[i].first; // We want to maximize A[i] in the subset
            minHeap.push(pairs[i].second);

            // Check if we can replace the smallest B[i] from the subset with the current B[i]
            if (minHeap.top() > pairs[i].second) {
                sum -= minHeap.top();
                minHeap.pop();
                minHeap.push(pairs[i].second);
            }
        }

        // The result for the current test case
        cout << maxA * sum << '\n';
    }
    return 0;
}