#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Generate all possible B sequences is not feasible due to O(N choose K) complexity.
    // Instead, we need a smarter approach.

    // The goal is to minimize (max(B) - min(B)) where B has length N-K and is formed by removing K elements from A.
    // Observation: After removing K elements, B must be a subsequence of A with length N-K, maintaining order.
    // We can't try all such subsequences directly. So we use a sliding window approach:

    // Idea: For any window of size (N-K), the difference between max and min in that window is a candidate.
    //       Find the minimum such difference among all windows of size (N-K).

    // Use a monotonic deque to efficiently maintain min and max in a sliding window.

    int windowSize = N - K;
    deque<int> minDeque, maxDeque;
    int result = INT_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain minDeque (increasing)
        while (!minDeque.empty() && A[minDeque.back()] >= A[i]) minDeque.pop_back();
        minDeque.push_back(i);

        // Maintain maxDeque (decreasing)
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i]) maxDeque.pop_back();
        maxDeque.push_back(i);

        // Remove indices out of window
        if (minDeque.front() <= i - windowSize) minDeque.pop_front();
        if (maxDeque.front() <= i - windowSize) maxDeque.pop_front();

        // Update result once window is valid
        if (i >= windowSize - 1) {
            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;

    return 0;
}