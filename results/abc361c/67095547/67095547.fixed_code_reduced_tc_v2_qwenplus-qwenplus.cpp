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

    // We need to remove K elements such that the difference between max and min in the remaining array is minimized.
    // The optimal way is to consider different combinations of removing elements from both ends.

    // Since we want minimum range (max - min), the idea is:
    // Try all possible ways to remove i elements from left and (K - i) from right (for valid i)
    // For each such split, compute the current window's max - min (which is A[right] - A[left])

    int min_diff = numeric_limits<int>::max();

    // Try all possible number of deletions from left (from 0 to K)
    for (int left_remove = 0; left_remove <= K; ++left_remove) {
        int right_remove = K - left_remove;
        if (left_remove + right_remove > N) continue;

        int l = left_remove;
        int r = N - 1 - right_remove;

        if (l <= r) {
            min_diff = min(min_diff, A[r] - A[l]);
        }
    }

    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}