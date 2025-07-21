#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    // We will slide a window of size L = N - K
    int L = N - K;
    int res = numeric_limits<int>::max();

    deque<int> dq;

    for (int i = 0; i < N; ++i) {
        // Maintain a deque of indices in the current window [i-L+1, i]
        while (!dq.empty() && dq.front() < i - L + 1)
            dq.pop_front();
        
        while (!dq.empty() && A[dq.back()].second > A[i].second)
            dq.pop_back();
        
        dq.push_back(i);

        if (i >= L - 1) {
            // Check if all N-K elements can be kept in order
            // i.e., they form a valid increasing subsequence in original index
            int minVal = A[i - L + 1].first;
            int maxVal = A[i].first;
            res = min(res, maxVal - minVal);
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