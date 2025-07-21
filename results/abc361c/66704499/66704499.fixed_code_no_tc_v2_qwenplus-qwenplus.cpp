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
    // and find the minimum difference between max and min in those windows
    int window_size = n - k;

    // Use a deque to maintain the maximum in sliding window
    deque<int> max_deque;
    // Use a deque to maintain the minimum in sliding window
    deque<int> min_deque;

    // Initialize the first window
    for (int i = 0; i < window_size; ++i) {
        // Maintain max deque
        while (!max_deque.empty() && A[i] >= A[max_deque.back()])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Maintain min deque
        while (!min_deque.empty() && A[i] <= A[min_deque.back()])
            min_deque.pop_back();
        min_deque.push_back(i);
    }

    int result = A[max_deque.front()] - A[min_deque.front()];

    // Slide the window
    for (int i = window_size; i < n; ++i) {
        // Remove elements outside the window
        while (!max_deque.empty() && max_deque.front() <= i - window_size)
            max_deque.pop_front();
        while (!min_deque.empty() && min_deque.front() <= i - window_size)
            min_deque.pop_front();

        // Add current element to deques
        // Max deque
        while (!max_deque.empty() && A[i] >= A[max_deque.back()])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Min deque
        while (!min_deque.empty() && A[i] <= A[min_deque.back()])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Update result
        result = min(result, A[max_deque.front()] - A[min_deque.front()]);
    }

    cout << result << endl;
    return 0;
}