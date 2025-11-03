#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We are removing exactly K elements, so we keep (N - K) elements.
    // The remaining elements must be a contiguous subarray in the sorted array
    // to minimize (max - min). We try all possible contiguous subarrays of length (N-K).

    int min_diff = INT_MAX;
    int remaining = N - K;

    for (int i = 0; i + remaining - 1 < N; i++) {
        int j = i + remaining - 1;
        min_diff = min(min_diff, A[j] - A[i]);
    }

    cout << min_diff << endl;

    return 0;
}