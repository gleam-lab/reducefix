#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all possible windows of size (n - K) in the array.
    // For each such window, we want to compute the max and min in that window.
    // The goal is to minimize (max - min) among all such windows.

    int window_size = n - K;
    deque<int> min_deque, max_deque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain min_deque as increasing sequence
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max_deque as decreasing sequence
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove elements out of the current window
        if (min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }
        if (max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }

        // Once the window is complete, update result
        if (i >= window_size - 1) {
            result = min(result, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << result << endl;
    return 0;
}