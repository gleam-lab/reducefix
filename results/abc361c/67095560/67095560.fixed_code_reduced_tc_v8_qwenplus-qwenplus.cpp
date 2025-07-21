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

    // We will consider all windows of size L = N - K and find min(max - min)
    int L = N - K;
    deque<int> maxDq, minDq;
    int res = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Remove elements out of the window
        while (!maxDq.empty() && maxDq.front() <= i - L) maxDq.pop_front();
        while (!minDq.empty() && minDq.front() <= i - L) minDq.pop_front();

        // Remove elements not useful (greater for max, smaller for min)
        while (!maxDq.empty() && A[maxDq.back()] <= A[i]) maxDq.pop_back();
        while (!minDq.empty() && A[minDq.back()] >= A[i]) minDq.pop_back();

        maxDq.push_back(i);
        minDq.push_back(i);

        // Once we have a valid window of size L, calculate difference
        if (i >= L - 1) {
            res = min(res, A[maxDq.front()] - A[minDq.front()]);
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