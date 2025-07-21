#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    int windowSize = n - k;

    deque<int> minDeque;
    deque<int> maxDeque;
    long long result = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain min deque (increasing)
        while (!minDeque.empty() && A[minDeque.back()] >= A[i])
            minDeque.pop_back();
        minDeque.push_back(i);

        // Maintain max deque (decreasing)
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i])
            maxDeque.pop_back();
        maxDeque.push_back(i);

        // Remove elements out of window
        while (!minDeque.empty() && minDeque.front() <= i - windowSize)
            minDeque.pop_front();

        while (!maxDeque.empty() && maxDeque.front() <= i - windowSize)
            maxDeque.pop_front();

        // Update answer once window size reached
        if (i >= windowSize - 1) {
            result = min(result, 1LL * A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;
    return 0;
}