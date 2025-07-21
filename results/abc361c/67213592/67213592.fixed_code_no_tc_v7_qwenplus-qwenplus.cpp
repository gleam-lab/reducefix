#include <iostream>
#include <vector>
#include <algorithm>
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

    // We need to remove exactly K elements to minimize the value: max(B) - min(B)
    // Since B is made from remaining elements in original order,
    // but we can choose which K to remove.

    // The key insight:
    // For any window of N-K elements in the original array, we can consider keeping this window and removing others.
    // Then the value is max(window) - min(window)
    // So we want to find the minimum difference over all windows of size N-K

    int window_size = n - k;
    vector<int> window_min;
    vector<int> window_max;
    
    // Use sliding window with deque-like logic to track min and max in window efficiently
    deque<int> min_deque;
    deque<int> max_deque;
    long long result = 1e18;

    for (int i = 0; i < n; ++i) {
        // Maintain min_deque for sliding window minimum
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max_deque for sliding window maximum
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove indices out of current window
        if (min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }
        if (max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }

        // Start calculating results after window is valid
        if (i >= window_size - 1) {
            result = min(result, (long long)(A[max_deque.front()] - A[min_deque.front()]));
        }
    }

    cout << result << endl;
}