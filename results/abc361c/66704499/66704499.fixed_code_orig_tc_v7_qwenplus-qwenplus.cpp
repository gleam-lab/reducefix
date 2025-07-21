#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to find the minimum possible value
    // of (max - min) over all subsequences of length N-K

    // To efficiently maintain max and min in a window of size N-K,
    // we can slide a window of size N-K across the array.

    deque<int> min_deque, max_deque;
    long long result = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain min_deque: elements are indices of A in increasing order of A[value]
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max_deque: elements are indices of A in decreasing order of A[value]
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove indices out of current window [i - (N-K-1), i]
        while (min_deque.front() < i - (N - K - 1)) {
            min_deque.pop_front();
        }
        while (max_deque.front() < i - (N - K - 1)) {
            max_deque.pop_front();
        }

        if (i >= N - K - 1) {
            result = min(result, 1LL * A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << result << endl;

    return 0;
}