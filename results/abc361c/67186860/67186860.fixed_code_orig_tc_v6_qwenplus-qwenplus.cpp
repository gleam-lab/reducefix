#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window to find the minimum possible value of max(B) - min(B)
    // where B is the sequence after removing exactly K elements.

    // To do this efficiently, we maintain a window of size (n - k) and slide it through A.
    // In each window, we compute the max and min in O(1) time using deques.

    deque<int> max_deque; // maintains indices of elements in window in decreasing order of A[i]
    deque<int> min_deque; // maintains indices of elements in window in increasing order of A[i]

    long long min_diff = numeric_limits<long long>::max();

    for (int i = 0; i < n; ++i) {
        // Remove indices out of the current window from both deques
        while (!max_deque.empty() && max_deque.front() <= i - (n - k)) max_deque.pop_front();
        while (!min_deque.empty() && min_deque.front() <= i - (n - k)) min_deque.pop_front();

        // Remove elements from the back of deques that are no longer useful
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) max_deque.pop_back();
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) min_deque.pop_back();

        max_deque.push_back(i);
        min_deque.push_back(i);

        // Once the window has reached size (n - k), calculate the difference
        if (i >= (n - k) - 1) {
            min_diff = min(min_diff, 1LL * A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << min_diff << endl;
    return 0;
}