#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int windowSize = N - K;

    deque<int> minDeque, maxDeque;
    int result = INT_MAX;

    // Sliding window setup
    for (int i = 0; i < N; ++i) {
        // Maintain increasing deque for minimum
        while (!minDeque.empty() && A[i] < A[minDeque.back()])
            minDeque.pop_back();
        // Maintain decreasing deque for maximum
        while (!maxDeque.empty() && A[i] > A[maxDeque.back()])
            maxDeque.pop_back();

        minDeque.push_back(i);
        maxDeque.push_back(i);

        // Remove elements out of the current window [i - windowSize + 1, i]
        if (i >= windowSize) {
            if (minDeque.front() <= i - windowSize)
                minDeque.pop_front();
            if (maxDeque.front() <= i - windowSize)
                maxDeque.pop_front();
        }

        // When window is valid, update result
        if (i >= windowSize - 1) {
            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;

    return 0;
}