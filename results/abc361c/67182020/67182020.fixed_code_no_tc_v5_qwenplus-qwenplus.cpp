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

    // We will consider all possible N-K length windows in the original array
    // and find the one with minimal (max - min)
    deque<int> maxdq;  // stores indices of elements in decreasing order
    deque<int> mindq;  // stores indices of elements in increasing order
    int windowSize = N - K;
    int result = INT_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain max deque
        while (!maxdq.empty() && A[i] > A[maxdq.back()]) {
            maxdq.pop_back();
        }
        maxdq.push_back(i);

        // Maintain min deque
        while (!mindq.empty() && A[i] < A[mindq.back()]) {
            mindq.pop_back();
        }
        mindq.push_back(i);

        // Remove out-of-window elements
        if (i >= windowSize) {
            if (maxdq.front() <= i - windowSize) {
                maxdq.pop_front();
            }
            if (mindq.front() <= i - windowSize) {
                mindq.pop_front();
            }
        }

        // Update result once window is complete
        if (i >= windowSize - 1) {
            result = min(result, A[maxdq.front()] - A[mindq.front()]);
        }
    }

    cout << result << endl;
    return 0;
}