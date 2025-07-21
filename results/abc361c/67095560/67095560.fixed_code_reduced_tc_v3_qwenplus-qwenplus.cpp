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

    int L = N - K; // Size of the sliding window

    deque<int> min_deque, max_deque;
    int result = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Remove elements out of the window
        while (!min_deque.empty() && min_deque.front() <= i - L)
            min_deque.pop_front();
        while (!max_deque.empty() && max_deque.front() <= i - L)
            max_deque.pop_front();

        // Maintain min deque (increasing)
        while (!min_deque.empty() && A[min_deque.back()] >= A[i])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Maintain max deque (decreasing)
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Once the window is filled
        if (i >= L - 1) {
            int current_min = A[min_deque.front()];
            int current_max = A[max_deque.front()];
            result = min(result, current_max - current_min);
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