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

    // We will consider all possible windows of size (n - k)
    int window_size = n - k;
    deque<int> min_deque, max_deque;
    long long min_result = numeric_limits<long long>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain deque for min and max in the current window

        // Remove elements out of the window
        while (!min_deque.empty() && min_deque.front() <= i - window_size)
            min_deque.pop_front();
        while (!max_deque.empty() && max_deque.front() <= i - window_size)
            max_deque.pop_front();

        // Remove elements not needed from the end
        while (!min_deque.empty() && A[i] <= A[min_deque.back()])
            min_deque.pop_back();
        while (!max_deque.empty() && A[i] >= A[max_deque.back()])
            max_deque.pop_back();

        min_deque.push_back(i);
        max_deque.push_back(i);

        // When window is formed, update result
        if (i >= window_size - 1) {
            min_result = min(min_result, 1LL * A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << min_result << "\n";

    return 0;
}