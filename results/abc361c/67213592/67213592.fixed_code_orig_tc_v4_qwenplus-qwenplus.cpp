#include <iostream>
#include <vector>
#include <deque>
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

    int window_size = n - k;

    deque<int> max_deque; // maintains indices of elements in decreasing order (max at front)
    deque<int> min_deque; // maintains indices of elements in increasing order (min at front)

    // Initialize first window
    for (int i = 0; i < window_size; ++i) {
        // Maintain max deque
        while (!max_deque.empty() && A[i] >= A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Maintain min deque
        while (!min_deque.empty() && A[i] <= A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);
    }

    long long min_diff = 1e18;

    for (int i = window_size; i <= n; ++i) {
        // Current window is [i - window_size, i - 1]
        long long current_diff = A[max_deque.front()] - A[min_deque.front()];
        min_diff = min(min_diff, current_diff);

        if (i == n) break;

        int out_of_window = i - window_size;
        int incoming = i;

        // Remove elements out of window
        if (max_deque.front() == out_of_window) {
            max_deque.pop_front();
        }
        if (min_deque.front() == out_of_window) {
            min_deque.pop_front();
        }

        // Add new element
        // Max deque
        while (!max_deque.empty() && A[incoming] >= A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(incoming);

        // Min deque
        while (!min_deque.empty() && A[incoming] <= A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(incoming);
    }

    cout << min_diff << endl;
}