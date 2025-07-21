#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to keep (n - K) elements
    int window_size = n - k;

    // Create a sliding window of size (n - k)
    deque<int> min_deque, max_deque;
    long long min_result = numeric_limits<long long>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain min_deque
        while (!min_deque.empty() && A[i] < A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max_deque
        while (!max_deque.empty() && A[i] > A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove indices out of the current window
        while (!min_deque.empty() && min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }
        while (!max_deque.empty() && max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }

        // Once we've formed the first complete window, start updating the result
        if (i >= window_size - 1) {
            min_result = min(min_result, (long long)(A[max_deque.front()] - A[min_deque.front()]));
        }
    }

    cout << min_result << endl;
    return 0;
}