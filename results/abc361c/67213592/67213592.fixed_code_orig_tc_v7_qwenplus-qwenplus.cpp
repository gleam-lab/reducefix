#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to remove exactly K elements to minimize (max(B) - min(B))
    // Since B is made by removing K elements and keeping order,
    // we can't sort the entire array.

    // Let's consider all possible windows of size (N-K) in A
    // and find the window with minimum (max - min)

    int window_size = N - K;
    if (window_size == 0) {
        cout << 0 << endl;
        return 0;
    }

    deque<int> max_deque;  // stores indices, values decreasing
    deque<int> min_deque;  // stores indices, values increasing

    long long min_diff = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain max_deque
        while (!max_deque.empty() && A[i] > A[max_deque.back()])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Maintain min_deque
        while (!min_deque.empty() && A[i] <= A[min_deque.back()])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Remove out-of-window elements
        if (i >= window_size) {
            while (!max_deque.empty() && max_deque.front() <= i - window_size)
                max_deque.pop_front();
            while (!min_deque.empty() && min_deque.front() <= i - window_size)
                min_deque.pop_front();
        }

        // Compute diff for valid window
        if (i >= window_size - 1) {
            long long current_diff = A[max_deque.front()] - A[min_deque.front()];
            min_diff = min(min_diff, current_diff);
        }
    }

    cout << min_diff << endl;
    return 0;
}