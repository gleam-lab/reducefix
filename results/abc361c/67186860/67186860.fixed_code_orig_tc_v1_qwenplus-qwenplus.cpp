#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to find the minimum possible value
    // of max(B) - min(B), where B is formed by removing exactly K elements.

    // The idea: we try all possible ways to keep (n - k) consecutive elements,
    // and within those windows, compute max - min. Since we can only remove K
    // elements, this is equivalent to selecting a subsequence of length (n - k)
    // in which the difference between max and min is minimized.

    int len = n - k;
    deque<int> min_deque, max_deque;
    int result = INT_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain min_deque with indices of increasing values
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max_deque with indices of decreasing values
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove out-of-window indices
        if (min_deque.front() <= i - len) {
            min_deque.pop_front();
        }
        if (max_deque.front() <= i - len) {
            max_deque.pop_front();
        }

        // Once we have a full window, calculate the difference
        if (i >= len - 1) {
            result = min(result, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << result << endl;
    return 0;
}