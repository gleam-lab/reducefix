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

    sort(A.begin(), A.end());

    int minDiff = numeric_limits<int>::max();
    int windowSize = N - K;

    // Slide a window of size (N-K) over the sorted array
    for (int i = 0; i + windowSize <= N; ++i) {
        minDiff = min(minDiff, A[i + windowSize - 1] - A[i]);
    }

    cout << minDiff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}