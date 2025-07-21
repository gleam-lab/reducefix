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
    // The answer is the minimum difference between max and min in such a window
    int window_size = n - K;
    
    // Use a deque to maintain min and max in the current window
    deque<int> min_deq;
    deque<int> max_deq;
    
    int result = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
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

        // Remove elements out of the current window
        if (min_deq.front() <= i - window_size) {
            min_deq.pop_front();
        }
        if (max_deq.front() <= i - window_size) {
            max_deq.pop_front();
        }

        // Start checking from when window is full
        if (i >= window_size - 1) {
            result = min(result, A[max_deq.front()] - A[min_deq.front()]);
        }
    }

    cout << result << endl;
    return 0;
}