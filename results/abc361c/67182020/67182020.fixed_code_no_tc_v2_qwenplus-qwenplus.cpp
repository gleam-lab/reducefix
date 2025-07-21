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

    deque<int> max_deque, min_deque;

    // Sliding window approach
    for (int i = 0; i < N; ++i) {
        // Remove elements outside the window
        while (!max_deque.empty() && max_deque.front() <= i - window_size)
            max_deque.pop_front();
        while (!min_deque.empty() && min_deque.front() <= i - window_size)
            min_deque.pop_front();

        // Add current element to deques
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        while (!min_deque.empty() && A[min_deque.back()] >= A[i])
            min_deque.pop_back();

        max_deque.push_back(i);
        min_deque.push_back(i);

        // Once window is formed (i >= window_size - 1)
        if (i >= window_size - 1) {
            int current_max = A[max_deque.front()];
            int current_min = A[min_deque.front()];
            min_diff = min(min_diff, current_max - current_min);
        }
    }

    cout << min_diff << endl;
    return 0;
}