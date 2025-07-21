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

    // We will consider all windows of size (N - K)
    // and find the minimum possible (max - min) among all such windows.
    deque<int> maxDq, minDq;
    long long result = numeric_limits<long long>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain deque for max
        while (!maxDq.empty() && A[maxDq.back()] <= A[i]) {
            maxDq.pop_back();
        }
        maxDq.push_back(i);

        // Maintain deque for min
        while (!minDq.empty() && A[minDq.back()] >= A[i]) {
            minDq.pop_back();
        }
        minDq.push_back(i);

        // Remove elements out of window [i-K+1, i]
        if (maxDq.front() <= i - (N - K)) {
            maxDq.pop_front();
        }
        if (minDq.front() <= i - (N - K)) {
            minDq.pop_front();
        }

        // When window size is achieved, compute current diff
        if (i >= (N - K - 1)) {
            long long currentDiff = (long long)A[maxDq.front()] - (long long)A[minDq.front()];
            result = min(result, currentDiff);
        }
    }

    cout << result << endl;
    return 0;
}