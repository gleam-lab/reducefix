#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to find the minimum range
    // After removing K elements, we need N-K elements remaining
    // So we consider all windows of size (N-K) in the original array and find the min max-min

    int window_size = N - K;
    int min_diff = numeric_limits<int>::max();

    for (int i = 0; i + window_size <= N; ++i) {
        // Find min and max in subarray A[i..i+window_size-1]
        multiset<int> window(A.begin() + i, A.begin() + i + window_size);
        int diff = *window.rbegin() - *window.begin();
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}