#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We are removing exactly K elements, so we keep (N - K) elements.
    // To minimize (max - min) of the remaining sequence,
    // we should consider contiguous segments of length (N - K) in the sorted array.
    // Because any non-contiguous selection can be improved by taking a contiguous block.

    int min_range = INT_MAX;
    int keep = N - K;

    // Try all possible contiguous segments of length 'keep'
    for (int i = 0; i + keep - 1 < N; ++i) {
        int current_range = A[i + keep - 1] - A[i];
        min_range = min(min_range, current_range);
    }

    cout << min_range << endl;

    return 0;
}