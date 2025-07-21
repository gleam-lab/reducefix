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

    // We need to find the minimum possible value of (max(B) - min(B)) where B is formed by
    // removing exactly K elements from A, keeping the order.

    // Since we can't try all combinations (too slow), we need a smarter approach.
    // The key idea: for any window of (n-K) elements, compute max-min.
    // We want the minimal such difference over all windows of size (n-K).

    // Use a sliding window and two deques to maintain current window's max and min.

    deque<int> maxD, minD;
    int res = LLONG_MAX;

    int l = 0;
    for (int r = 0; r < n; ++r) {
        // Maintain max deque (descending)
        while (!maxD.empty() && A[r] > maxD.back()) maxD.pop_back();
        maxD.push_back(A[r]);

        // Maintain min deque (ascending)
        while (!minD.empty() && A[r] < minD.back()) minD.pop_back();
        minD.push_back(A[r]);

        // When window size exceeds (n-K), move left forward
        if (r - l + 1 > n - K) {
            if (maxD.front() == A[l]) maxD.pop_front();
            if (minD.front() == A[l]) minD.pop_front();
            ++l;
        }

        // Once window is valid (size n-K), update result
        if (r - l + 1 == n - K) {
            res = min(res, maxD.front() - minD.front());
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