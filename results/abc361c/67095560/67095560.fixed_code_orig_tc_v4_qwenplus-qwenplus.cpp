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

    int L = N - K;
    deque<int> maxdq, mindq;
    int res = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain maxdq for maximum in window
        while (!maxdq.empty() && A[i] > A[maxdq.back()])
            maxdq.pop_back();
        maxdq.push_back(i);

        // Maintain mindq for minimum in window
        while (!mindq.empty() && A[i] < A[mindq.back()])
            mindq.pop_back();
        mindq.push_back(i);

        // Remove elements out of window
        while (!maxdq.empty() && maxdq.front() <= i - L)
            maxdq.pop_front();
        while (!mindq.empty() && mindq.front() <= i - L)
            mindq.pop_front();

        if (i >= L - 1) {
            res = min(res, A[maxdq.front()] - A[mindq.front()]);
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