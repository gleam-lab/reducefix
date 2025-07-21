#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    // Sliding window min and max using deques
    deque<int> minDeque, maxDeque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain min deque (increasing)
        while (!minDeque.empty() && A[minDeque.back()] >= A[i])
            minDeque.pop_back();
        minDeque.push_back(i);

        // Maintain max deque (decreasing)
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i])
            maxDeque.pop_back();
        maxDeque.push_back(i);

        // Remove elements out of the current window of size N-K
        if (i >= N - K - 1) {
            while (minDeque.front() <= i - N + K)
                minDeque.pop_front();
            while (maxDeque.front() <= i - N + K)
                maxDeque.pop_front();

            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}