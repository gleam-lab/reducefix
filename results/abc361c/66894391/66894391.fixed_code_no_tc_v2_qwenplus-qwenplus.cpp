#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to keep N - K elements
    // and find the minimum (max - min) over all windows of size N - K
    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    // To efficiently get min and max in a window, we'll use two deques
    deque<int> max_deque;  // stores indices of elements in decreasing order
    deque<int> min_deque;  // stores indices of elements in increasing order

    for (int i = 0; i < n; ++i) {
        // Remove elements outside the window
        while (!max_deque.empty() && max_deque.front() <= i - window_size)
            max_deque.pop_front();
        while (!min_deque.empty() && min_deque.front() <= i - window_size)
            min_deque.pop_front();

        // Remove smaller elements from max_deque
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        // Remove larger elements from min_deque
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