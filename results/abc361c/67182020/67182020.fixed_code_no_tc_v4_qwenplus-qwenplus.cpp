#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will consider all windows of size N - K
    // and find the min(max - min) among them.

    int window_size = N - K;
    int min_diff = numeric_limits<int>::max();

    // Sliding window approach using deque to track min and max
    deque<int> max_deque, min_deque;

    for (int i = 0; i < N; ++i) {
        // Maintain deque for max
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Maintain deque for min
        while (!min_deque.empty() && A[min_deque.back()] >= A[i])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Remove elements out of the current window
        if (i >= window_size) {
            if (max_deque.front() <= i - window_size)
                max_deque.pop_front();
            if (min_deque.front() <= i - window_size)
                min_deque.pop_front();
        }

        // Calculate min difference for each valid window
        if (i >= window_size - 1) {
            min_diff = min(min_diff, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << min_diff << endl;
    return 0;
}