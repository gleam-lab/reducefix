#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window to find the minimum possible value of (max - min)
    // in any subsequence of length (n - k) that preserves original order.
    // Use a monotonic deque to maintain min and max in window.

    deque<int> min_deq, max_deq;
    int res = INF;

    for (int i = 0; i < n; ++i) {
        // Maintain deque for min
        while (!min_deq.empty() && A[i] <= A[min_deq.back()])
            min_deq.pop_back();
        min_deq.push_back(i);

        // Maintain deque for max
        while (!max_deq.empty() && A[i] >= A[max_deq.back()])
            max_deq.pop_back();
        max_deq.push_back(i);

        // Remove elements out of window
        while (!min_deq.empty() && min_deq.front() <= i - (n - k))
            min_deq.pop_front();
        while (!max_deq.empty() && max_deq.front() <= i - (n - k))
            max_deq.pop_front();

        // When window size reaches (n - k), calculate difference
        if (i >= (n - k - 1)) {
            res = min(res, A[max_deq.front()] - A[min_deq.front()]);
        }
    }

    cout << res << endl;
}