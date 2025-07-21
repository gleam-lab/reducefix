#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int window_size = N - K;
    deque<int> min_deque, max_deque;
    int result = INT_MAX;

    for (int i = 0; i < N; ++i) {
        // Remove indices out of current window
        while (!min_deque.empty() && min_deque.front() <= i - window_size)
            min_deque.pop_front();
        while (!max_deque.empty() && max_deque.front() <= i - window_size)
            max_deque.pop_front();

        // Maintain monotonic increasing deque for min
        while (!min_deque.empty() && A[min_deque.back()] >= A[i])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Maintain monotonic decreasing deque for max
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Start computing when window is full
        if (i >= window_size - 1) {
            int current_diff = A[max_deque.front()] - A[min_deque.front()];
            result = min(result, current_diff);
        }
    }

    cout << result << endl;
    return 0;
}