#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all possible windows of size (n - K) in the original array
    // The value we want to minimize is max(window) - min(window)
    // Use sliding window with deque for efficient max/min tracking

    int window_size = n - k;
    deque<int> max_dq;  // stores indices, A[i] decreasing
    deque<int> min_dq;  // stores indices, A[i] increasing
    int result = numeric_limits<int>::max();

    // Initialize the first window
    for (int i = 0; i < window_size; ++i) {
        while (!max_dq.empty() && A[i] >= A[max_dq.back()]) max_dq.pop_back();
        while (!min_dq.empty() && A[i] <= A[min_dq.back()]) min_dq.pop_back();
        max_dq.push_back(i);
        min_dq.push_back(i);
    }

    result = A[max_dq.front()] - A[min_dq.front()];

    // Slide the window
    for (int i = window_size; i < n; ++i) {
        // Remove elements outside the window
        if (max_dq.front() <= i - window_size) max_dq.pop_front();
        if (min_dq.front() <= i - window_size) min_dq.pop_front();

        // Add new element
        while (!max_dq.empty() && A[i] >= A[max_dq.back()]) max_dq.pop_back();
        while (!min_dq.empty() && A[i] <= A[min_dq.back()]) min_dq.pop_back();
        max_dq.push_back(i);
        min_dq.push_back(i);

        // Update result
        result = min(result, A[max_dq.front()] - A[min_dq.front()]);
    }

    cout << result << endl;
    return 0;
}