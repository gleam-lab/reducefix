#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to choose N-K elements in order to minimize the range (max - min)
    // Try all possible windows of size (N-K) in the original array
    // and track the minimum range found

    int window_size = N - K;
    int min_range = numeric_limits<int>::max();

    // Use a deque to keep track of min and max in O(1) per operation
    deque<int> max_deque;
    deque<int> min_deque;

    for (int i = 0; i < N; ++i) {
        // Maintain max_deque: elements are in decreasing order
        while (!max_deque.empty() && A[i] > max_deque.back()) {
            max_deque.pop_back();
        }
        max_deque.push_back(A[i]);

        // Maintain min_deque: elements are in increasing order
        while (!min_deque.empty() && A[i] < min_deque.back()) {
            min_deque.pop_back();
        }
        min_deque.push_back(A[i]);

        // Remove elements out of window
        if (i >= window_size) {
            if (A[i - window_size] == max_deque[0]) {
                max_deque.pop_front();
            }
            if (A[i - window_size] == min_deque[0]) {
                min_deque.pop_front();
            }
        }

        // Once window is full, update min range
        if (i >= window_size - 1) {
            min_range = min(min_range, max_deque[0] - min_deque[0]);
        }
    }

    cout << min_range << endl;
    return 0;
}