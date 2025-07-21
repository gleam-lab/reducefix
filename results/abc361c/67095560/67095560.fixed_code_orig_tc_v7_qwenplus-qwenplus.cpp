#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int L = N - K; // Length of the subarray we are considering
    deque<int> maxDq, minDq;
    int result = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain deque for max
        while (!maxDq.empty() && A[i] > A[maxDq.back()])
            maxDq.pop_back();
        maxDq.push_back(i);

        // Maintain deque for min
        while (!minDq.empty() && A[i] < A[minDq.back()])
            minDq.pop_back();
        minDq.push_back(i);

        // Remove elements out of window
        if (i >= L) {
            while (!maxDq.empty() && maxDq.front() <= i - L)
                maxDq.pop_front();
            while (!minDq.empty() && minDq.front() <= i - L)
                minDq.pop_front();
        }

        // Update result when window is full
        if (i >= L - 1) {
            result = min(result, A[maxDq.front()] - A[minDq.front()]);
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