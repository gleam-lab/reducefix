#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We'll use a sliding window of size (N - K)
    int window_size = N - K;
    int min_diff = numeric_limits<int>::max();

    // Two possible strategies:
    // 1. Try all windows of size (N-K) in the original array
    //    and compute max-min in each.
    // But that's O(N^2) in worst case.

    // Better idea: we can process all windows using deque to maintain
    // max and min in O(N) total time.

    deque<int> max_dq, min_dq;
    for (int i = 0; i < N; ++i) {
        // Maintain deque for max
        while (!max_dq.empty() && A[max_dq.back()] <= A[i]) max_dq.pop_back();
        max_dq.push_back(i);

        // Remove elements out of window from front
        while (!max_dq.empty() && max_dq.front() <= i - window_size) max_dq.pop_front();

        // Maintain deque for min
        while (!min_dq.empty() && A[min_dq.back()] >= A[i]) min_dq.pop_back();
        min_dq.push_back(i);

        // Remove elements out of window from front
        while (!min_dq.empty() && min_dq.front() <= i - window_size) min_dq.pop_front();

        if (i >= window_size - 1) {
            min_diff = min(min_diff, A[max_dq.front()] - A[min_dq.front()]);
        }
    }

    cout << min_diff << endl;
    return 0;
}