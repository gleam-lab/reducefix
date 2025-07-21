#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int W = N - K;
    deque<int> minQ, maxQ;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain min deque
        while (!minQ.empty() && A[minQ.back()] >= A[i])
            minQ.pop_back();
        minQ.push_back(i);

        // Maintain max deque
        while (!maxQ.empty() && A[maxQ.back()] <= A[i])
            maxQ.pop_back();
        maxQ.push_back(i);

        // Remove out of window indices
        if (minQ.front() <= i - W)
            minQ.pop_front();
        if (maxQ.front() <= i - W)
            maxQ.pop_front();

        if (i >= W - 1) {
            int currentDiff = A[maxQ.front()] - A[minQ.front()];
            result = min(result, currentDiff);
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