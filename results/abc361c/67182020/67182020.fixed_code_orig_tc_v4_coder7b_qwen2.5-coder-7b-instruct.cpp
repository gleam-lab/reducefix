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

    sort(A.begin(), A.end());

    int min_diff = INT_MAX;

    // Scenario 1: Remove K/2 elements from both ends
    if (K % 2 == 0) {
        min_diff = min(min_diff, A[N - K / 2] - A[K / 2]);
    }

    // Scenario 2: Remove (K+1)/2 elements from one end and (K-1)/2 elements from the other end
    if (K % 2 != 0) {
        min_diff = min(min_diff, max(A[N - K / 2 - 1] - A[K / 2 + 1], A[N - K / 2] - A[K / 2]));
    }

    cout << min_diff << endl;

    return 0;
}