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

    // We will consider the minimum possible value of max(B) - min(B)
    // where B is formed by deleting exactly K elements from A.
    // This means B has length N - K.

    // To minimize max(B) - min(B), we can try sliding a window of size (N-K)
    // over the sorted array and find the minimum difference between max and min in that window.

    sort(A.begin(), A.end());

    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i + (N - K) <= N; ++i) {
        min_diff = min(min_diff, A[i + (N - K)] - A[i]);
    }

    cout << min_diff;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}