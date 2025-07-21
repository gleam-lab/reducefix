#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Edge case where k is greater than n, though the problem states k < n.
    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }

    // Deque to store the minimums of the current window.
    deque<int> min_deque;
    // Deque to store the maximums of the current window.
    deque<int> max_deque;

    // Initialize the deques.
    for (int i = 0; i < n; ++i) {
        // Maintain the deque for maximums: remove elements not within the window.
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        // Maintain the deque for minimums: remove elements not within the window.
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        // Add current element to both deques.
        max_deque.push_back(i);
        min_deque.push_back(i);

        // If the window has more than n-k elements, remove the oldest ones.
        if (i >= k) {
            max_deque.pop_front();
            min_deque.pop_front();
        }
    }

    // The answer is the minimum difference for any window of size n-k.
    int answer = INT_MAX;
    for (int i = 0; i + k - 1 < n; ++i) {
        int max_val = A[max_deque.front()];
        int min_val = A[min_deque.front()];
        answer = min(answer, max_val - min_val);
    }

    cout << answer << endl;
    return 0;
}