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

    // We are removing exactly K elements.
    // So we keep M = N - K elements.
    // The remaining elements must be contiguous in the sorted array to minimize (max - min).
    // Why? Because if we skip an element in the middle, we could potentially get a smaller range by shifting.

    int M = N - K;
    ll min_diff = A[M - 1] - A[0]; // First window: [0, M-1]

    // Try all possible contiguous segments of length M
    for (int i = 1; i + M - 1 < N; ++i) {
        ll diff = A[i + M - 1] - A[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    cout << min_diff << endl;

    return 0;
}