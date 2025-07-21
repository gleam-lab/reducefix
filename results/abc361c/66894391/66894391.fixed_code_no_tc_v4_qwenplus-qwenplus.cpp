#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all possible windows of size (n - K)
    // The goal is to find the window where max - min is minimized
    int window_size = n - k;
    deque<int> max_deque, min_deque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain deque for maximum values
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Maintain deque for minimum values
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Remove elements out of the current window
        if (max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }
        if (min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }

        // When window is valid, update result
        if (i >= window_size - 1) {
            result = min(result, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << result << endl;
    return 0;
}