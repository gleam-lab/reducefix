#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to find the minimum possible value of (max(B) - min(B)) where B is a subsequence
    // of A with length (n - k), formed by removing exactly K elements.

    // Since we want to minimize max(B) - min(B), and B must be a contiguous subsequence of size (n-K)
    // in the original order, we can consider all windows of size (n-K) in the array and compute
    // the min difference over all such windows.

    int window_size = n - k;
    deque<int> max_dq;  // stores indices, elements in decreasing order
    deque<int> min_dq;  // stores indices, elements in increasing order
    int ans = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain max_dq
        while (!max_dq.empty() && A[max_dq.back()] <= A[i]) max_dq.pop_back();
        max_dq.push_back(i);

        // Maintain min_dq
        while (!min_dq.empty() && A[min_dq.back()] >= A[i]) min_dq.pop_back();
        min_dq.push_back(i);

        // Remove out-of-window elements
        if (i >= window_size - 1) {
            while (max_dq.front() <= i - window_size) max_dq.pop_front();
            while (min_dq.front() <= i - window_size) min_dq.pop_front();
            ans = min(ans, A[max_dq.front()] - A[min_dq.front()]);
        }
    }

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}