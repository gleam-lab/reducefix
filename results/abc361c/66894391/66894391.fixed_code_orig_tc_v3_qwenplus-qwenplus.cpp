#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sliding window size
    int windowSize = N - K;

    deque<int> maxDeque;
    deque<int> minDeque;
    int result = INT_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain maxDeque: elements are in decreasing order
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // Maintain minDeque: elements are in increasing order
        while (!minDeque.empty() && A[minDeque.back()] >= A[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // Remove out-of-bound indices (when window has started moving)
        while (maxDeque.front() <= i - windowSize) {
            maxDeque.pop_front();
        }
        while (minDeque.front() <= i - windowSize) {
            minDeque.pop_front();
        }

        // Once the first window is complete, start computing results
        if (i >= windowSize - 1) {
            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;

    return 0;
}