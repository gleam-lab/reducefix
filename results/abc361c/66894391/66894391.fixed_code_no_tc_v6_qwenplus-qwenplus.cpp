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
    // in the original array and find min and max in each window.
    // The final answer is the minimum of (max - min) over all such windows.

    deque<int> min_deq, max_deq;
    int window_size = n - k;
    long long min_diff = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain min_deq: indices of elements in increasing order
        while (!min_deq.empty() && A[min_deq.back()] >= A[i])
            min_deq.pop_back();
        min_deq.push_back(i);

        // Maintain max_deq: indices of elements in decreasing order
        while (!max_deq.empty() && A[max_deq.back()] <= A[i])
            max_deq.pop_back();
        max_deq.push_back(i);

        // Remove indices outside the current window
        if (min_deq.front() <= i - window_size)
            min_deq.pop_front();
        if (max_deq.front() <= i - window_size)
            max_deq.pop_front();

        // Start checking once the window is full
        if (i >= window_size - 1) {
            min_diff = min(min_diff, 1LL * A[max_deq.front()] - A[min_deq.front()]);
        }
    }

    cout << min_diff << endl;
    return 0;
}