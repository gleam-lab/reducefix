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

    // Deques to maintain elements for min and max in sliding window
    deque<int> min_deq;
    deque<int> max_deq;
    long long result = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain min_deq: elements are in increasing order
        while (!min_deq.empty() && A[min_deq.back()] >= A[i]) {
            min_deq.pop_back();
        }
        min_deq.push_back(i);

        // Maintain max_deq: elements are in decreasing order
        while (!max_deq.empty() && A[max_deq.back()] <= A[i]) {
            max_deq.pop_back();
        }
        max_deq.push_back(i);

        // Remove elements out of window [i - (N-K)+1, i]
        while (min_deq.front() <= i - (N - K)) {
            min_deq.pop_front();
        }
        while (max_deq.front() <= i - (N - K)) {
            max_deq.pop_front();
        }

        // Once window is valid (after first N-K-1 steps)
        if (i >= N - K - 1) {
            result = min(result, 1LL * (A[max_deq.front()] - A[min_deq.front()]));
        }
    }

    cout << result << endl;
    return 0;
}