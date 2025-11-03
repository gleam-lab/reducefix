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
    // The remaining elements must be contiguous in the sorted array to minimize the range.
    // Try all possible contiguous subarrays of length (N - K)
    ll min_range = LLONG_MAX;
    int keep = N - K;

    for (int i = 0; i + keep - 1 < N; ++i) {
        int j = i + keep - 1;
        min_range = min(min_range, (ll)A[j] - A[i]);
    }

    cout << min_range << endl;

    return 0;
}