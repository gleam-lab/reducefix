#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    int window_size = n - k;

    deque<int> min_deque, max_deque;
    int result = INT_MAX;

    for (int i = 0; i < n; ++i) {
        // Remove indices out of current window
        if (!min_deque.empty() && min_deque.front() <= i - window_size)
            min_deque.pop_front();
        if (!max_deque.empty() && max_deque.front() <= i - window_size)
            max_deque.pop_front();

        // Maintain min deque: increasing order
        while (!min_deque.empty() && A[min_deque.back()] >= A[i])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Maintain max deque: decreasing order
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Start calculating when window is complete
        if (i >= window_size - 1) {
            int current_diff = A[max_deque.front()] - A[min_deque.front()];
            result = min(result, current_diff);
        }
    }

    cout << result << endl;
}