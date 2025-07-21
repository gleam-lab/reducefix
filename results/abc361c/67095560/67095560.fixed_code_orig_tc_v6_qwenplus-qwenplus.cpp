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

    // Sort the array
    sort(A.begin(), A.end());

    int minDiff = LLONG_MAX;
    // Slide a window of size N-K
    for (int i = 0; i + (N - K - 1) < N; ++i) {
        minDiff = min(minDiff, A[i + (N - K - 1)] - A[i]);
    }

    cout << minDiff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}