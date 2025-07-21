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
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // Maintain minDeque: elements are in increasing order
        while (!minDeque.empty() && A[minDeque.back()] >= A[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // Remove out-of-window elements
        if (i >= windowSize) {
            if (maxDeque.front() <= i - windowSize) {
                maxDeque.pop_front();
            }
            if (minDeque.front() <= i - windowSize) {
                minDeque.pop_front();
            }
        }

        // Once window is complete, update result
        if (i >= windowSize - 1) {
            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;

    return 0;
}