#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Sort the candidates based on the number of votes received
    sort(A.begin(), A.end());

    // Prepare to calculate the minimum votes needed for each candidate
    vector<long long> additionalVotes(N, -1);

    // Iterate over the sorted list to determine the minimum votes needed
    for (int i = 0; i < N; ++i) {
        // The candidate in M-th position (0-indexed) will be the boundary
        int boundary = min(i + M, N) - 1;

        // Calculate the votes needed to surpass the M-th candidate
        if (A[i] < A[boundary]) {
            additionalVotes[i] = A[boundary] - A[i] + 1;
        } else {
            // If the current candidate already has more votes than the M-th candidate,
            // they need no additional votes.
            additionalVotes[i] = 0;
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << (additionalVotes[i] > 0 ? additionalVotes[i] : -1) << (i < N - 1 ? " " : "\n");
    }

    return 0;
}