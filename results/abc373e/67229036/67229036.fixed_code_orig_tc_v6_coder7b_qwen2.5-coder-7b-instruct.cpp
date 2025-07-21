#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N), B(N + 1), C(N);

    // Read initial vote counts
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
        B[i + 1] = A[i];
    }

    // Compute prefix sums for quick access
    partial_sum(B.begin(), B.end(), B.begin());

    // For each candidate, compute the minimum additional votes needed
    for (int i = 0; i < N; ++i) {
        // Calculate the votes needed for candidate i to win
        long long needed = A[i] + M - 1;

        // Find the smallest j such that the sum of votes from j onwards minus the current votes of candidate i is greater than needed
        auto it = lower_bound(B.rbegin() + 1, B.rend(), needed + A[i]);
        int j = distance(it, B.rend()) - 1;

        // If no such j exists, candidate i cannot win under any circumstances
        if (j == 0 || B[j] <= A[i]) {
            C[i] = -1;
        } else {
            C[i] = B[j] - A[i] - needed;
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}