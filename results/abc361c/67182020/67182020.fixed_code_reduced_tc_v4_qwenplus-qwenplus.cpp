#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to remove K elements such that the resulting array has length N-K.
    // Our goal is to minimize (max(B) - min(B)), where B is the resulting array.

    // Since we want the minimum difference between max and min,
    // the idea is to consider all possible windows of size (N-K) in the sorted array.
    // Because once we sort A, any window of size (N-K) represents a candidate for B.
    // From those, we pick the one with minimal (max - min).

    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    long long min_diff = numeric_limits<long long>::max();
    for (int i = 0; i + (N - K) <= N; ++i) {
        min_diff = min(min_diff, 1LL * sorted_A[i + (N - K)] - sorted_A[i]);
    }

    cout << min_diff << endl;

    return 0;
}