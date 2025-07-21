#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());

    // Initialize the minimum difference to a large number
    long long min_diff = LLONG_MAX;

    // Use sliding window to find the minimum difference
    for (int i = 0; i <= N - K; ++i) {
        long long current_diff = A[i + K - 1] - A[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    // Output the result
    cout << min_diff << endl;

    return 0;
}