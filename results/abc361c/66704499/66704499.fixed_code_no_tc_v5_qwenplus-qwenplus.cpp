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
    // The goal is to minimize max(B) - min(B) where B is the sequence after removing K elements

    // Since we must keep N - K elements in original order, we can slide a window of size N - K over the array
    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    // Use a deque to maintain min and max in the window efficiently (sliding window min/max)
    deque<int> min_deque, max_deque;

    // Initialize the first window
    for (int i = 0; i < window_size; ++i) {
        // Maintain min_deque: elements are in increasing order
        while (!min_deque.empty() && A[i] < min_deque.back()) {
            min_deque.pop_back();
        }
        min_deque.push_back(A[i]);

        // Maintain max_deque: elements are in decreasing order
        while (!max_deque.empty() && A[i] > max_deque.back()) {
            max_deque.pop_back();
        }
        max_deque.push_back(A[i]);
    }

    min_diff = max_deque.front() - min_deque.front();

    // Slide the window
    for (int i = window_size; i < n; ++i) {
        // Remove element going out of the window
        if (A[i - window_size] == min_deque.front()) {
            min_deque.pop_front();
        }
        if (A[i - window_size] == max_deque.front()) {
            max_deque.pop_front();
        }

        // Add new element into the deques
        // Maintain min_deque
        while (!min_deque.empty() && A[i] < min_deque.back()) {
            min_deque.pop_back();
        }
        min_deque.push_back(A[i]);

        // Maintain max_deque
        while (!max_deque.empty() && A[i] > max_deque.back()) {
            max_deque.pop_back();
        }
        max_deque.push_back(A[i]);

        // Update minimum difference
        min_diff = min(min_diff, max_deque.front() - min_deque.front());
    }

    cout << min_diff << endl;
    return 0;
}