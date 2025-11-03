#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We need to remove exactly K elements, leaving N-K elements.
    // The remaining elements must be contiguous in the sorted array to minimize (max - min).
    // Try all possible contiguous segments of length (N-K) in the sorted array.
    int min_diff = INT_MAX;
    int remaining = N - K;

    for (int i = 0; i + remaining - 1 < N; ++i) {
        int j = i + remaining - 1;
        min_diff = min(min_diff, A[j] - A[i]);
    }

    cout << min_diff << endl;

    return 0;
}