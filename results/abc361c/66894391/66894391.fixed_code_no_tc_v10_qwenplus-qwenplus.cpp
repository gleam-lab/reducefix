#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all possible windows of size N-K in the original array
    // because we must keep exactly N-K elements in order
    // So we slide a window of size N-K across the array and find min and max in each window
    // The answer is the minimum value of (max - min) among all such windows

    deque<int> min_deque, max_deque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Remove elements outside the window
        if (!min_deque.empty() && min_deque.front() <= i - (n - k)) {
            min_deque.pop_front();
        }
        if (!max_deque.empty() && max_deque.front() <= i - (n - k)) {
            max_deque.pop_front();
        }

        // Add current element to deques
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }

        min_deque.push_back(i);
        max_deque.push_back(i);

        // Start calculating when the window is full
        if (i >= (n - k) - 1) {
            result = min(result, max_deque.front() - min_deque.front());
        }
    }

    cout << result << endl;
    return 0;
}