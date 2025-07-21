#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will consider the minimum possible value of (max - min)
    // over all subsequences of size (N-K)

    // Sliding window approach: maintain a window of size (N-K)
    // and track min and max in each window

    // Optimization: use two deques to track min and max efficiently
    deque<int> min_dq, max_dq;
    int res = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Remove elements out of window
        while (!min_dq.empty() && min_dq.front() <= i - (N - K)) {
            min_dq.pop_front();
        }
        while (!max_dq.empty() && max_dq.front() <= i - (N - K)) {
            max_dq.pop_front();
        }

        // Remove elements from back that are not min/max
        while (!min_dq.empty() && A[min_dq.back()] >= A[i]) {
            min_dq.pop_back();
        }
        while (!max_dq.empty() && A[max_dq.back()] <= A[i]) {
            max_dq.pop_back();
        }

        min_dq.push_back(i);
        max_dq.push_back(i);

        // When window is full
        if (i >= (N - K) - 1) {
            res = min(res, A[max_dq.front()] - A[min_dq.front()]);
        }
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}