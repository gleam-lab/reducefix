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

    // We need to find the minimum possible value of max(B) - min(B)
    // where B is formed by removing exactly K elements from A.
    // Since min and max are involved, we can try sorting.

    // When we remove K elements, we keep (N-K) elements.
    // So we need to choose a subsequence of length (N-K) in original order,
    // such that the difference between the max and min of this subsequence is minimized.

    // Key insight: If we sort the array, then the minimal difference will occur when we consider:
    // For every window of size (N-K), compute max - min
    // The minimum among all these windows is our answer.

    sort(A.begin(), A.end());

    int min_diff = LLONG_MAX;
    for (int i = 0; i + (N - K) <= N; ++i) {
        min_diff = min(min_diff, A[i + (N - K)] - A[i]);
    }

    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}