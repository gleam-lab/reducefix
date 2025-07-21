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
    deque<int> maxDeque, minDeque;
    long long minDiff = LLONG_MAX;

    // Initialize first window
    for (int i = 0; i < windowSize; ++i) {
        while (!maxDeque.empty() && A[i] >= A[maxDeque.back()])
            maxDeque.pop_back();
        while (!minDeque.empty() && A[i] <= A[minDeque.back()])
            minDeque.pop_back();
        maxDeque.push_back(i);
        minDeque.push_back(i);
    }

    minDiff = A[maxDeque.front()] - A[minDeque.front()];

    // Slide window
    for (int i = windowSize; i < N; ++i) {
        // Remove elements out of window
        while (!maxDeque.empty() && maxDeque.front() <= i - windowSize)
            maxDeque.pop_front();
        while (!minDeque.empty() && minDeque.front() <= i - windowSize)
            minDeque.pop_front();

        // Add current element to deques
        while (!maxDeque.empty() && A[i] >= A[maxDeque.back()])
            maxDeque.pop_back();
        while (!minDeque.empty() && A[i] <= A[minDeque.back()])
            minDeque.pop_back();

        maxDeque.push_back(i);
        minDeque.push_back(i);

        minDiff = min(minDiff, (long long)(A[maxDeque.front()] - A[minDeque.front()]));
    }

    cout << minDiff << endl;
}