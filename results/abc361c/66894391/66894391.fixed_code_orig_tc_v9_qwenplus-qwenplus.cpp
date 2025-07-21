#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all possible intervals of size (n - K)
    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    // Prepare a sliding window minimum and maximum using deque
    deque<int> max_deque, min_deque;
    
    for (int i = 0; i < n; ++i) {
        // Maintain deque for maximum
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove elements out of window
        if (max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }

        // Maintain deque for minimum
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Remove elements out of window
        if (min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }

        // Start checking once the window is large enough
        if (i >= window_size - 1)        {
            min_diff = min(min_diff, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << min_diff << endl;
    return 0;
}