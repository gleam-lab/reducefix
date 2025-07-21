#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int windowSize = N - K;
    deque<int> minDeque, maxDeque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain min deque: elements are in increasing order
        while (!minDeque.empty() && A[i] < A[minDeque.back()]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // Maintain max deque: elements are in decreasing order
        while (!maxDeque.empty() && A[i] > A[maxDeque.back()]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // Remove out-of-window elements
        if (i >= windowSize) {
            if (minDeque.front() <= i - windowSize) {
                minDeque.pop_front();
            }
            if (maxDeque.front() <= i - windowSize) {
                maxDeque.pop_front();
            }
        }

        // Update result once window is valid
        if (i >= windowSize - 1) {
            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;
    return 0;
}