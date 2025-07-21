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

    // We will consider all windows of size N-K in the array
    // and find the one that minimizes (max - min)
    int window_size = N - K;
    deque<int> max_deque, min_deque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain deque for max
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Maintain deque for min
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Remove elements out of the current window
        if (i >= window_size) {
            while (!max_deque.empty() && max_deque.front() <= i - window_size) {
                max_deque.pop_front();
            }
            while (!min_deque.empty() && min_deque.front() <= i - window_size) {
                min_deque.pop_front();
            }
        }

        // When window is full, calculate difference
        if (i >= window_size - 1) {
            result = min(result, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << result << endl;
    return 0;
}