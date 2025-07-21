#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int window_size = n - k;

    deque<int> max_deque;
    deque<int> min_deque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain max_deque: elements are in decreasing order
        while (!max_deque.empty() && A[i] > A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Maintain min_deque: elements are in increasing order
        while (!min_deque.empty() && A[i] < A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Remove elements out of window
        while (!max_deque.empty() && max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }
        while (!min_deque.empty() && min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }

        // Once window is valid, update result
        if (i >= window_size - 1) {
            result = min(result, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << result << endl;

    return 0;
}