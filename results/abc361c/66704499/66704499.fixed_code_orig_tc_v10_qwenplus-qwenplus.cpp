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

    int windowSize = N - K;
    deque<int> maxDeque, minDeque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain maxDeque: elements are in decreasing order
        while (!maxDeque.empty() && A[i] > A[maxDeque.back()]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // Maintain minDeque: elements are in increasing order
        while (!minDeque.empty() && A[i] < A[minDeque.back()]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // Remove elements out of the current window
        while (!maxDeque.empty() && maxDeque.front() <= i - windowSize) {
            maxDeque.pop_front();
        }
        while (!minDeque.empty() && minDeque.front() <= i - windowSize) {
            minDeque.pop_front();
        }

        // Once window is full, calculate the range
        if (i >= windowSize - 1) {
            int currentMax = A[maxDeque.front()];
            int currentMin = A[minDeque.front()];
            result = min(result, currentMax - currentMin);
        }
    }

    cout << result << endl;
    return 0;
}