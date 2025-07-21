#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int L = N - K; // Length of the subarray to consider

    deque<int> minDeque, maxDeque;
    long long result = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Remove indices out of the current window
        while (!minDeque.empty() && minDeque.front() <= i - L)
            minDeque.pop_front();
        while (!maxDeque.empty() && maxDeque.front() <= i - L)
            maxDeque.pop_front();

        // Maintain minDeque in increasing order
        while (!minDeque.empty() && A[minDeque.back()] >= A[i])
            minDeque.pop_back();
        // Maintain maxDeque in decreasing order
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i])
            maxDeque.pop_back();

        minDeque.push_back(i);
        maxDeque.push_back(i);

        // Start checking once the window has enough elements
        if (i >= L - 1) {
            result = min(result, 1LL * A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;
    return 0;
}