#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    // Sort the array to consider elements in increasing order
    sort(A.begin(), A.end());

    // We need to remove exactly K elements to minimize the difference
    // between max and min of the remaining N-K elements.
    // Try all possible windows of size (N-K)
    int windowSize = n - k;
    int minDiff = A[windowSize - 1] - A[0];

    for (int i = 1; i + windowSize <= n; ++i) {
        int currentDiff = A[i + windowSize - 1] - A[i];
        minDiff = min(minDiff, currentDiff);
    }

    cout << minDiff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}