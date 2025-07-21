#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to keep K elements
    // So we need to remove N - K elements
    // We slide a window of size N - K over the sorted array
    int window_size = N - K;
    sort(A.begin(), A.end());

    int min_diff = INT_MAX;
    for (int i = 0; i + window_size <= N; ++i) {
        chmin(min_diff, A[i + window_size - 1] - A[i]);
    }

    cout << min_diff << '\n';
    return 0;
}