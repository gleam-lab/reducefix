#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int windowSize = N - K;
    
    deque<int> maxDeque, minDeque;
    int result = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain maxDeque for window
        while (!maxDeque.empty() && maxDeque.front() <= i - windowSize)
            maxDeque.pop_front();
        while (!maxDeque.empty() && A[maxDeque.back()] < A[i])
            maxDeque.pop_back();
        maxDeque.push_back(i);

        // Maintain minDeque for window
        while (!minDeque.empty() && minDeque.front() <= i - windowSize)
            minDeque.pop_front();
        while (!minDeque.empty() && A[minDeque.back()] > A[i])
            minDeque.pop_back();
        minDeque.push_back(i);

        if (i >= windowSize - 1) {
            int currentMax = A[maxDeque.front()];
            int currentMin = A[minDeque.front()];
            result = min(result, currentMax - currentMin);
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