#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int windowSize = N - K;

    deque<int> maxDeque, minDeque;
    int result = LLONG_MAX;

    // Sliding window with deques for max and min
    for (int i = 0; i < N; ++i) {
        // Maintain maxDeque: elements in decreasing order
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // Maintain minDeque: elements in increasing order
        while (!minDeque.empty() && A[minDeque.back()] >= A[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // Remove out-of-window indices
        if (i >= windowSize) {
            if (maxDeque.front() <= i - windowSize) {
                maxDeque.pop_front();
            }
            if (minDeque.front() <= i - windowSize) {
                minDeque.pop_front();
            }
        }

        // Once window is valid, compute diff
        if (i >= windowSize - 1) {
            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}